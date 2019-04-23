#include "Utility.h"
#include <Psapi.h>

Utility Util;

unsigned int Utility::FindPattern(std::string moduleName, std::string pattern, bool relativeOffset)
{
	const char* pat = pattern.c_str();
	uintptr_t firstMatch = 0;
	uintptr_t rangeStart = (uintptr_t)GetModuleHandleA(moduleName.c_str());
	MODULEINFO miModInfo; GetModuleInformation(GetCurrentProcess(), (HMODULE)rangeStart, &miModInfo, sizeof(MODULEINFO));
	uintptr_t rangeEnd = rangeStart + miModInfo.SizeOfImage;

	for (uintptr_t pCur = rangeStart; pCur < rangeEnd; pCur++) {
		if (!*pat)
			break;

		if (*(PBYTE)pat == '\?' || *(BYTE*)pCur == getByte(pat)) {
			if (!firstMatch)
				firstMatch = pCur;

			if (!pat[2])
				break;

			if (*(PWORD)pat == '\?\?' || *(PBYTE)pat != '\?')
				pat += 3;

			else
				pat += 2; 
		}
		else {
			pat = pattern.c_str();
			firstMatch = 0;
		}
	}

	if (relativeOffset)
		firstMatch = firstMatch + 0x5 + *(DWORD*)(firstMatch + 0x1);
	return firstMatch;
}

void D3D9RenderState::SaveState(IDirect3DDevice9 * pDevice)
{
	pDevice->GetRenderState(D3DRS_COLORWRITEENABLE, &dwOld_D3DRS_COLORWRITEENABLE);
	pDevice->GetVertexDeclaration(&vertDec);
	pDevice->GetVertexShader(&vertShader);
	pDevice->SetRenderState(D3DRS_COLORWRITEENABLE, 0xffffffff);
	pDevice->SetRenderState(D3DRS_SRGBWRITEENABLE, false);
	pDevice->SetSamplerState(NULL, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
	pDevice->SetSamplerState(NULL, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);
	pDevice->SetSamplerState(NULL, D3DSAMP_ADDRESSW, D3DTADDRESS_WRAP);
	pDevice->SetSamplerState(NULL, D3DSAMP_SRGBTEXTURE, NULL);
}

void D3D9RenderState::RestoreState(IDirect3DDevice9 * pDevice)
{
	pDevice->SetRenderState(D3DRS_COLORWRITEENABLE, dwOld_D3DRS_COLORWRITEENABLE);
	pDevice->SetRenderState(D3DRS_SRGBWRITEENABLE, true);
	pDevice->SetVertexDeclaration(vertDec);
	pDevice->SetVertexShader(vertShader);
}
