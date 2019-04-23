#include "CVMT.h"

uintptr_t* CVMT::GetEmptyDataPage(const char* module_name, const size_t vmt_size)
{
	auto check_data_section = [&](LPCVOID address, const size_t vmt_size)
	{
		const DWORD DataProtection = (PAGE_EXECUTE_READWRITE | PAGE_READWRITE);
		MEMORY_BASIC_INFORMATION mbi = { 0 };

		if (VirtualQuery(address, &mbi, sizeof(mbi)) == sizeof(mbi) && mbi.AllocationBase && mbi.BaseAddress &&
			mbi.State == MEM_COMMIT && !(mbi.Protect & PAGE_GUARD) && mbi.Protect != PAGE_NOACCESS)
		{
			if ((mbi.Protect & DataProtection) && mbi.RegionSize >= vmt_size)
			{
				return ((mbi.Protect & DataProtection) && mbi.RegionSize >= vmt_size) ? true : false;
			}
		}
		return false;
	};

	auto module_addr = GetModuleHandleA(module_name);

	if (module_addr == nullptr)
		return nullptr;

	const auto dos_header = reinterpret_cast<PIMAGE_DOS_HEADER> (module_addr);
	const auto nt_headers = reinterpret_cast<PIMAGE_NT_HEADERS> (reinterpret_cast<uint8_t*>(module_addr) + dos_header->e_lfanew);

	const auto module_end = reinterpret_cast<uintptr_t>(module_addr) + nt_headers->OptionalHeader.SizeOfImage - sizeof(uintptr_t);

	for (auto current_address = module_end; current_address > (DWORD)module_addr; current_address -= sizeof(uintptr_t))
	{
		if (*reinterpret_cast<uintptr_t*>(current_address) == 0 && check_data_section(reinterpret_cast<LPCVOID>(current_address), vmt_size))
		{
			bool is_good_vmt = true;
			auto page_count = 0u;

			for (; page_count < vmt_size && is_good_vmt; page_count += sizeof(uintptr_t))
			{
				if (*reinterpret_cast<uintptr_t*>(current_address + page_count) != 0)
					is_good_vmt = false;
			}

			if (is_good_vmt && page_count >= vmt_size)
				return (uintptr_t*)current_address;
		}
	}
	return nullptr;
}

CVMT::CVMT()
	: classBase(nullptr), vtableLenght(0), newVtable(nullptr), oldVtable(nullptr)
{
}
CVMT::CVMT(void* base)
	: classBase(base), vtableLenght(0), newVtable(nullptr), oldVtable(nullptr)
{
}
CVMT::~CVMT()
{
	UnHookAll();
	if (wasAllocated)
		delete[] newVtable;
}

auto table_is_hooked(void* table, const char* module_table_dst) -> const bool
{
	// Because of this probable check you can make a VEH Hook by forcing the pointer to 0
	if (table == nullptr) // Not initialized or invalid table to check
		return false;

	const auto module_base = GetModuleHandleA(module_table_dst);

	// Get module end
	const auto dos_header = reinterpret_cast<PIMAGE_DOS_HEADER> (module_base);
	const auto nt_headers = reinterpret_cast<PIMAGE_NT_HEADERS> (reinterpret_cast<std::uint8_t*>(module_base) + dos_header->e_lfanew);

	const auto module_end = reinterpret_cast<std::uintptr_t>(module_base) + nt_headers->OptionalHeader.SizeOfImage - sizeof(std::uintptr_t);

	const auto table_dst = *reinterpret_cast<std::uintptr_t*>(table);

	// Check the destination of the table, if the destination of the table is outside the region of the module, it is because it has been changed(hooked)
	return (table_dst < reinterpret_cast<std::uintptr_t>(module_base) || table_dst > module_end);
}

bool CVMT::Setup(void* base)
{
	std::string moduleName;

	if (base != nullptr)
		classBase = base;

	if (classBase == nullptr)
		return false;

	oldVtable = *(std::uintptr_t**)classBase;
	vtableLenght = EstimateVtableLenght(oldVtable) * sizeof(std::uintptr_t);

	if (vtableLenght == 0)
		return false;

	MEMORY_BASIC_INFORMATION mbi = { 0 };
	if (VirtualQuery(base, &mbi, sizeof(mbi))) // Grab the path from the alocationbase aka the module and then extract the module name from it.
	{
		char buffer[MAX_PATH];
		GetModuleFileNameA((HMODULE)mbi.AllocationBase, buffer, MAX_PATH);
		std::string temp = buffer;
		const size_t last_slash_idx = temp.find_last_of("\\/");
		if (std::string::npos != last_slash_idx)
			temp.erase(0, last_slash_idx + 1), moduleName = temp;
	}
	if (moduleName.size())// If provided a module name then we will find a place in that module				
	{
		newVtable = GetEmptyDataPage(moduleName.c_str(), vtableLenght + sizeof(std::uintptr_t));
		std::memset(newVtable, NULL, vtableLenght + sizeof(std::uintptr_t));
		std::memcpy(&newVtable[1], oldVtable, vtableLenght);
		newVtable[0] = oldVtable[-1];
		try {
			auto guard = ProtectGuard{ classBase, sizeof(std::uintptr_t), PAGE_READWRITE };

			*(std::uintptr_t**)classBase = &newVtable[1];
			wasAllocated = false;
			if (table_is_hooked(base, moduleName.c_str()))
				throw std::runtime_error((std::string("Table Not hooked!!! - ") + moduleName).c_str());
		}
		catch (...) {
			delete[] newVtable;
			return false;
		}
	}
	else // If not then we do regular vmthookinh
	{
		newVtable = new std::uintptr_t[vtableLenght + 1]();
		std::memcpy(&newVtable[1], oldVtable, vtableLenght);
		try {
			auto guard = ProtectGuard{ classBase, sizeof(std::uintptr_t), PAGE_READWRITE };
			newVtable[0] = oldVtable[-1];
			*(std::uintptr_t**)classBase = &newVtable[1];
			wasAllocated = true;
		}
		catch (...) {
			delete[] newVtable;
			return false;
		}
	}


	return true;
}

size_t CVMT::EstimateVtableLenght(uintptr_t* vftbl_start)
{
	MEMORY_BASIC_INFORMATION memInfo = { NULL };
	int m_nSize = -1;
	do {
		m_nSize++;
		VirtualQuery(reinterpret_cast<LPCVOID>(vftbl_start[m_nSize]), &memInfo, sizeof(memInfo));

	} while (memInfo.Protect == PAGE_EXECUTE_READ || memInfo.Protect == PAGE_EXECUTE_READWRITE);

	return m_nSize;
}