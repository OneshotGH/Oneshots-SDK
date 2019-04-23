#include "Hooks.h"
#include <functional>
CHooks * Hooking = nullptr;

CHooks::CHooks()
{
	IDirect3DDevice9 * d3d9Device = **(IDirect3DDevice9***)(Util.FindPattern("shaderapidx9.dll", "A1 ?? ?? ?? ?? 50 8B 08 FF 51 0C") + 1);

	D3DDEVICE_CREATION_PARAMETERS parameters{};
	d3d9Device->GetCreationParameters(&parameters);
	oWndProc = (WNDPROC)SetWindowLongPtr(G.Window = parameters.hFocusWindow, GWL_WNDPROC, (LONG_PTR)Hooks::WndProc);

	if (d3d9.Setup((void*)d3d9Device))
	{
		oEndScene = (EndSceneFn)d3d9.HookIndex(42, Hooks::EndScene);
		oReset = (ResetFn)d3d9.HookIndex(16, Hooks::Reset);
	}

	if (ClientMode.Setup(Interfaces->ClientMode))
	{
		oCreateMove = (CreateMoveFn)ClientMode.HookIndex(24, Hooks::CreateMove);
	}
	if (Panel.Setup(Interfaces->Panel))
	{
		oPaintTraverse = (PaintTraverseFn)Panel.HookIndex(41, Hooks::PaintTraverse);
	}
}
CHooks::~CHooks()
{
	SetWindowLongPtr(G.Window, GWL_WNDPROC, (LONG_PTR)oWndProc);
}



