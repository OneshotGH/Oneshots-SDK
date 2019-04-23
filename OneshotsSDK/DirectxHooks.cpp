#include "Hooks.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx9.h"
#include "ImGui/imgui_impl_win32.h"

D3D9RenderState state;
EndSceneFn oEndScene;

HRESULT __stdcall Hooks::EndScene(IDirect3DDevice9 * pDevice)
{
	static DWORD ret = (DWORD)_ReturnAddress();
	if (ret != (DWORD)_ReturnAddress()) // Endscene is called twice so this prevents us from rendering twice.
		return oEndScene(pDevice);
	
	static bool init = true;
	if (init)
	{
		ImGui::CreateContext();
		ImGui::GetIO().MouseDrawCursor = true;
		ImGui_ImplDX9_Init(pDevice);
		ImGui_ImplWin32_Init(G.Window);
		init = false;
	}

	/*simple toogle code for the menu*/
	static bool toogle = false;
	{	
		if (GetAsyncKeyState(VK_INSERT) && !toogle)
			G.MenuOpen = !G.MenuOpen, toogle = true;
		else if (!GetAsyncKeyState(VK_INSERT) && toogle)
			toogle = false;
		
		if (G.MenuOpen)
			Interfaces->Input->m_fMouseInitialized = false , Interfaces->Input->m_fMouseActive = false;
		else
			Interfaces->Input->m_fMouseInitialized = true;
	}

	if (G.MenuOpen)
	{
		state.SaveState(pDevice);

		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		
		ImGui::Begin("Insert p2c name here :')", &G.MenuOpen);
		ImGui::Checkbox("Bhop", &Config.bhop);
		ImGui::SameLine();
		ImGui::Checkbox("Esp", &Config.esp);
		if (ImGui::Button("Eject Cheat"))
			G.Exit = true;

		ImGui::End();

		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		state.RestoreState(pDevice);
	}

	return oEndScene(pDevice);
}

ResetFn oReset;

long __stdcall Hooks::Reset(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
	long hr = oReset(pDevice, pPresentationParameters);
	G.Window = pPresentationParameters->hDeviceWindow;
	ImGui_ImplDX9_CreateDeviceObjects();
	return hr;
}

WNDPROC oWndProc;
IMGUI_IMPL_API LRESULT  ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT __stdcall Hooks::WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (G.MenuOpen)
	{
		if (ImGui::GetCurrentContext())
			ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);		
		return true;
	}
	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}