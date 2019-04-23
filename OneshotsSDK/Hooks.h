#pragma once
#include "MainHeader.h"

class CHooks
{
public:
	CHooks();
	~CHooks();
public:

public:
	CVMT d3d9;
	CVMT ClientMode;
	CVMT Panel;
};

extern CHooks * Hooking;

extern WNDPROC oWndProc;

using EndSceneFn = long(__stdcall*)(IDirect3DDevice9* device);
extern EndSceneFn oEndScene;

using ResetFn = long(__stdcall*)(IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* pp);
extern ResetFn oReset;

using CreateMoveFn = bool(__stdcall*)(float, CUserCmd*);
extern CreateMoveFn oCreateMove;

using PaintTraverseFn = void(__thiscall*)(void*, unsigned int, bool, bool);
extern PaintTraverseFn oPaintTraverse;
namespace Hooks
{
	HRESULT __stdcall EndScene(IDirect3DDevice9 * pDevice);
	long __stdcall Reset(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);
	LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	bool __stdcall CreateMove(float flInputSampleTime, CUserCmd * cmd);
	void __stdcall PaintTraverse(unsigned int panel, bool forceRepaint, bool allowForce);
}