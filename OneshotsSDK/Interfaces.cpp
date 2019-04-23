#include "Interfaces.h"
#include <Windows.h>
#include "Utility.h"

CInterfaces * Interfaces = nullptr;

class InterfaceReg
{
private:

	using InstantiateInterfaceFn = void*(*)();

public:

	InstantiateInterfaceFn m_CreateFn;
	const char *m_pName;

	InterfaceReg *m_pNext;
};

template<typename T>
static T *GetInterface(const char *module, const char *name)
{
	static unsigned int CreateInterfaceFn = reinterpret_cast<unsigned int>(GetProcAddress(GetModuleHandleA(module), "CreateInterface"));
	if (!CreateInterfaceFn)
		return nullptr;

	T *inter = nullptr;
	 nullptr;
	int len = strlen(name);

	unsigned int target = (unsigned int)(CreateInterfaceFn) + *(unsigned int*)((unsigned int)(CreateInterfaceFn) + 5) + 9;

	InterfaceReg *interfaceRegList = **reinterpret_cast<InterfaceReg***>(target + 6);

	for (InterfaceReg *cur = interfaceRegList; cur; cur = cur->m_pNext)
	{
		if (!strncmp(cur->m_pName, name, len) && std::atoi(cur->m_pName + len) > 0)
			inter = reinterpret_cast<T*>(cur->m_CreateFn());
	}
	return inter;
}

CInterfaces::CInterfaces()
{
	Client = GetInterface<IBaseClientDLL>("client_panorama.dll", "VClient0");
	Globals = **(CGlobalVarsBase***)((*(uintptr_t**)Client)[0] + 0x1B);
	ClientMode = **(IClientMode***)((*(DWORD**)Client)[10] + 0x5);
	Server = GetInterface<IServerGameDLL>("server.dll", "ServerGameDLL0");
	Panel = GetInterface<IVPanel>("vgui2.dll", "VGUI_Panel");
	ClientEntityList = GetInterface<IClientEntityList>("client_panorama.dll", "VClientEntityList");
	EngineClient = GetInterface<IEngineClient>("engine.dll", "VEngineClient");
	InputSystem = GetInterface<IInputSystem>("inputsystem.dll", "InputSystemVersion");
	Input = *(CInput**)(Util.FindPattern("client_panorama.dll", "B9 ? ? ? ? F3 0F 11 04 24 FF 50 10") + 0x1);
	Surface = GetInterface<ISurface>("vguimatsurface.dll", "VGUI_Surface");
	EngineTrace = GetInterface<IEngineTrace>("engine.dll", "EngineTraceClient");
}
