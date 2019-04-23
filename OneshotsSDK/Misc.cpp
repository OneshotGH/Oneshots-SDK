#include "Misc.h"
CMisc * Misc = nullptr;
void CMisc::Bhop(CBaseEntity * local, CUserCmd * cmd)
{
	if (!Config.bhop || !local)
		return;

	if (cmd->buttons & IN_JUMP && !(local->GetFlags() & FL_ONGROUND))
		cmd->buttons &= ~IN_JUMP;
}

