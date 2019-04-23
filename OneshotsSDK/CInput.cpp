#include "CInput.h"
#include "Utility.h"


CUserCmd *CInput::GetUserCmd(int nSlot, int sequence_number)
{
	typedef CUserCmd*(__thiscall *GetUserCmd_t)(void*, int, int);
	return Util.GetVFunc<GetUserCmd_t>(this, 8)(this, nSlot, sequence_number);
}
CUserCmd* CInput::GetUserCmd(int sequence_number)
{
	return &m_pCommands[sequence_number % MULTIPLAYER_BACKUP];
}
CVerifiedUserCmd* CInput::GetVerifiedCmd(int sequence_number)
{
	return &m_pVerifiedCommands[sequence_number % MULTIPLAYER_BACKUP];
}