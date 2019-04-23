#pragma once
#include <Windows.h>
#include <stdint.h>
#include <string>
#include <assert.h>

class ProtectGuard
{
public:
	ProtectGuard(void* base, size_t len, std::uint32_t flags)
	{
		base = base;
		length = len;
		if (!VirtualProtect(base, len, flags, (PDWORD)&_old))
			throw std::runtime_error("Failed to protect region.");
	}
	~ProtectGuard()
	{
		VirtualProtect(base, length, _old, (PDWORD)&_old);
	}

private:
	void*         base;
	size_t        length;
	uint32_t _old;
};

class CVMT
{
public:
	uintptr_t * GetEmptyDataPage(const char * module_name, const size_t vmt_size);
	CVMT();
	CVMT(void* base);
	~CVMT();

	bool Setup(void * base);

	template<typename T>
	uintptr_t HookIndex(int index, T fun)
	{
		assert(index >= 0 && index <= (int)vtableLenght);
		newVtable[index + 1] = reinterpret_cast<std::uintptr_t>(fun);
		return oldVtable[index];
	}
	void UnHookIndex(int index)
	{
		newVtable[index] = oldVtable[index];
	}
	void UnHookAll()
	{
		try {
			if (oldVtable != nullptr) {
				auto guard = ProtectGuard{ classBase, sizeof(std::uintptr_t), PAGE_READWRITE };
				*(uintptr_t**)classBase = oldVtable;
				oldVtable = nullptr;
			}
		}
		catch (...) {
		}
	}

	template<typename T>
	T GetOriginal(int index)
	{
		return (T)oldVtable[index];
	}

private:

	static inline size_t EstimateVtableLenght(uintptr_t* vftbl_start);

	void*           classBase;
	size_t     vtableLenght;
	uintptr_t* newVtable;
	uintptr_t* oldVtable;
	LPCVOID         SearchBase = nullptr;
	bool wasAllocated = false;
};