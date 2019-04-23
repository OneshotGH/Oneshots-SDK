#pragma once

#include "UserCmd.h"
#include "Vector.h"
#include "QAngle.h"

#define MULTIPLAYER_BACKUP 150

class bf_write;
class bf_read;

class CInput
{
public:
	virtual void  Init_All(void) = 0;
	virtual void  Shutdown_All(void) = 0;
	virtual int   GetButtonBits(int) = 0;
	virtual void  CreateMove(int sequence_number, float input_sample_frametime, bool active) = 0;
	virtual void  ExtraMouseSample(float frametime, bool active) = 0;
	virtual bool  WriteUsercmdDeltaToBuffer(bf_write *buf, int from, int to, bool isnewcommand) = 0;
	virtual void  EncodeUserCmdToBuffer(bf_write& buf, int slot) = 0;
	virtual void  DecodeUserCmdFromBuffer(bf_read& buf, int slot) = 0;

	CUserCmd *GetUserCmd(int nSlot, int sequence_number);
	inline CUserCmd* GetUserCmd(int sequence_number);
	inline CVerifiedUserCmd* GetVerifiedCmd(int sequence_number);
	char pad_0x00[0x8];
	bool                m_fTrackIRAvailable;
	bool                m_fMouseInitialized;
	bool                m_fMouseActive;
	bool                m_fJoystickAdvancedInit;
	char                pad_0x08[0x2C];
	void*               m_pKeys;
	char                pad_0x38[0x64];
	int                 pad_0x41;
	int                 pad_0x42;
	bool                m_fCameraInterceptingMouse;
	bool                m_fCameraInThirdPerson;
	bool                m_fCameraMovingWithMouse;
	Vector              m_vecCameraOffset;
	bool                m_fCameraDistanceMove;
	int                 m_nCameraOldX;
	int                 m_nCameraOldY;
	int                 m_nCameraX;
	int                 m_nCameraY;
	bool                m_CameraIsOrthographic;
	Vector              m_angPreviousViewAngles;
	Vector              m_angPreviousViewAnglesTilt;
	float               m_flLastForwardMove;
	int                 m_nClearInputState;
	char                pad_0xE4[0x8];
	CUserCmd*           m_pCommands;
	CVerifiedUserCmd*   m_pVerifiedCommands;
};

