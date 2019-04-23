#pragma once
#include "IBaseClientDLL.h"
#include "GlobalVars.h"
#include "IServerGameDLL.h"
#include "IClientMode.h"
#include "IVPanel.h"
#include "IClientEntityList.h"
#include "IEngineClient.h"
#include "IInputSystem.h"
#include "CInput.h"
#include "ISurface.h"
#include "IEngineTrace.h"
class CInterfaces
{
public:
	CInterfaces();
public:
	IBaseClientDLL		* Client = nullptr;
	CGlobalVarsBase		* Globals = nullptr;
	IServerGameDLL		* Server = nullptr;
	IClientMode			* ClientMode = nullptr;
	IVPanel				* Panel = nullptr;
	IClientEntityList   * ClientEntityList = nullptr;
	IEngineClient		* EngineClient = nullptr;
	IInputSystem		* InputSystem = nullptr;
	CInput				* Input = nullptr;
	ISurface			* Surface = nullptr;
	IEngineTrace		* EngineTrace = nullptr;
};

extern CInterfaces * Interfaces;