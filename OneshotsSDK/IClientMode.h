#pragma once
#include "Matrix3x4_t.h"
#include "QAngle.h"
class IPanel;
class C_BaseEntity;

enum class ClearFlags_t
{
	VIEW_CLEAR_COLOR = 0x1,
	VIEW_CLEAR_DEPTH = 0x2,
	VIEW_CLEAR_FULL_TARGET = 0x4,
	VIEW_NO_DRAW = 0x8,
	VIEW_CLEAR_OBEY_STENCIL = 0x10,
	VIEW_CLEAR_STENCIL = 0x20,
};


enum class MotionBlurMode_t
{
	MOTION_BLUR_DISABLE = 1,
	MOTION_BLUR_GAME = 2,
	MOTION_BLUR_SFM = 3
};

class CViewSetup
{
public:
	int			x, x_old;
	int			y, y_old;
	int			width, width_old;
	int			height, height_old;
	bool		m_bOrtho;
	float		m_OrthoLeft;
	float		m_OrthoTop;
	float		m_OrthoRight;
	float		m_OrthoBottom;
	bool		m_bCustomViewMatrix;
	matrix3x4_t	m_matCustomViewMatrix;
	char		pad_0x68[0x48];
	float		fov;
	float		fovViewmodel;
	Vector		origin;
	QAngle		angles;
	float		zNear;
	float		zFar;
	float		zNearViewmodel;
	float		zFarViewmodel;
	float		m_flAspectRatio;
	float		m_flNearBlurDepth;
	float		m_flNearFocusDepth;
	float		m_flFarFocusDepth;
	float		m_flFarBlurDepth;
	float		m_flNearBlurRadius;
	float		m_flFarBlurRadius;
	int			m_nDoFQuality;
	int			m_nMotionBlurMode;
	float		m_flShutterTime;
	Vector		m_vShutterOpenPosition;
	QAngle		m_shutterOpenAngles;
	Vector		m_vShutterClosePosition;
	QAngle		m_shutterCloseAngles;
	float		m_flOffCenterTop;
	float		m_flOffCenterBottom;
	float		m_flOffCenterLeft;
	float		m_flOffCenterRight;
	int			m_EdgeBlur;

};//Size=0x014C

class IClientMode
{
public:
	virtual             ~IClientMode() {}
	virtual int         ClientModeCSNormal(void *) = 0;
	virtual void        Init() = 0;
	virtual void        InitViewport() = 0;
	virtual void        Shutdown() = 0;
	virtual void        Enable() = 0;
	virtual void        Disable() = 0;
	virtual void        Layout() = 0;
	virtual IPanel*     GetViewport() = 0;
	virtual void*       GetViewportAnimationController() = 0;
	virtual void        ProcessInput(bool bActive) = 0;
	virtual bool        ShouldDrawDetailObjects() = 0;
	virtual bool        ShouldDrawEntity(C_BaseEntity *pEnt) = 0;
	virtual bool        ShouldDrawLocalPlayer(C_BaseEntity *pPlayer) = 0;
	virtual bool        ShouldDrawParticles() = 0;
	virtual bool        ShouldDrawFog(void) = 0;
	virtual void        OverrideView(CViewSetup *pSetup) = 0;
	virtual int         KeyInput(int down, int keynum, const char *pszCurrentBinding) = 0;
	virtual void        StartMessageMode(int iMessageModeType) = 0;
	virtual IPanel*     GetMessagePanel() = 0;
	virtual void        OverrideMouseInput(float *x, float *y) = 0;
	virtual bool        CreateMove(float flInputSampleTime, void* usercmd) = 0;
	virtual void        LevelInit(const char *newmap) = 0;
	virtual void        LevelShutdown(void) = 0;
};