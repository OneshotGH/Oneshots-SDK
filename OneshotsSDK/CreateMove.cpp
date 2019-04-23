#include "Hooks.h"
#include "Interfaces.h"
CreateMoveFn oCreateMove;

bool __stdcall Hooks::CreateMove(float flInputSampleTime, CUserCmd* cmd)
{
	uintptr_t *framePtr;
	__asm mov framePtr, ebp;

	if (!cmd->command_number || !Interfaces->EngineClient->IsInGame() || !Interfaces->EngineClient->IsConnected())
		return oCreateMove(flInputSampleTime, cmd);

	CBaseEntity * local = (CBaseEntity *)Interfaces->ClientEntityList->GetClientEntity(Interfaces->EngineClient->GetLocalPlayer());

	Misc->Bhop(local, cmd);
	
	*(bool*)(*framePtr - 0x1C) = G.SendPacket, G.SendPacket = true;
	return false;
}