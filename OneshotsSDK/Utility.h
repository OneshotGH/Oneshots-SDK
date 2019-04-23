#pragma once
#include "MainHeader.h"
#include <string>

#define INRANGE(x,a,b)    (x >= a && x <= b) 
#define getBits( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define getByte( x )    (getBits(x[0]) << 4 | getBits(x[1]))

class D3D9RenderState
{
public:
	void SaveState(IDirect3DDevice9 * pDevice);
	void RestoreState(IDirect3DDevice9 * pDevice);
private:
	IDirect3DStateBlock9* pixel_state = nullptr;
	IDirect3DVertexDeclaration9* vertDec = nullptr;
	IDirect3DVertexShader9* vertShader = nullptr;
	DWORD dwOld_D3DRS_COLORWRITEENABLE = NULL;
};

class Utility
{
public:
	unsigned int FindPattern(std::string moduleName, std::string pattern, bool relativeOffset = false);

	template <typename T, int i = -1>
	constexpr T GetVFunc(void *vTable, int index = 0) noexcept {
		return (*reinterpret_cast<T**>(vTable))[(i >= 0 ? i : index)];
	}
};

extern Utility Util;
