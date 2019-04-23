#pragma once
#include <Windows.h>

class CheatGlobalVars
{
public:
	HMODULE module = NULL;
	bool MenuOpen = false;
	bool Exit = false;
	bool SendPacket = false;
	HWND Window = NULL;
};

extern CheatGlobalVars G;