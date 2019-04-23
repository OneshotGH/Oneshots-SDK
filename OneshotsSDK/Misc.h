#pragma once
#include "MainHeader.h"
#include "CBaseEntity.h"
class CMisc
{
public:
	void Bhop(CBaseEntity * local , CUserCmd * cmd);
};

extern CMisc * Misc;