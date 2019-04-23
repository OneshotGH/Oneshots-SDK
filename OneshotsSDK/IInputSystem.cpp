#include "IInputSystem.h"

void IInputSystem::DisableAllInput(bool disable)
{
	static void * mouseAddress = *(void**)((char*)this + *(int*)((*(char***)this)[10] + 5));
	*(void**)((char*)this + *(int*)((*(char***)this)[10] + 5)) = disable ? 0 : mouseAddress;
}

void IInputSystem::EnableInput(bool bEnable)
{
	typedef void(__thiscall* OriginalFn)(void*, bool);
	return callvfunc<OriginalFn>(this, 11)(this, bEnable);
}

void IInputSystem::ResetInputState()
{
	typedef void(__thiscall* OriginalFn)(void*);
	return callvfunc<OriginalFn>(this, 39)(this);
}

bool IInputSystem::IsButtonDown(ButtonCode_t code)
{
	typedef bool(__thiscall* OriginalFn)(void*, ButtonCode_t);
	bool pressed = callvfunc<OriginalFn>(this, 15)(this, code);
	return pressed;
}

void IInputSystem::GetCursorPosition(int* m_pX, int* m_pY)
{
	typedef void(__thiscall* OriginalFn)(void*, int*, int*);
	return callvfunc<OriginalFn>(this, 56)(this, m_pX, m_pY);
}

const char* IInputSystem::ButtonCodeToString(ButtonCode_t ButtonCode)
{
	typedef const char*(__thiscall* OriginalFn)(void*, ButtonCode_t);
	return callvfunc<OriginalFn>(this, 40)(this, ButtonCode);
}

ButtonCode_t IInputSystem::VirtualKeyToButtonCode(int nVirtualKey)
{
	typedef ButtonCode_t(__thiscall* OriginalFn)(void*, int);
	return callvfunc<OriginalFn>(this, 44)(this, nVirtualKey);
}

int IInputSystem::ButtonCodeToVirtualKey(ButtonCode_t code)
{
	typedef int(__thiscall* OriginalFn)(void*, ButtonCode_t);
	return callvfunc<OriginalFn>(this, 45)(this, code);
}