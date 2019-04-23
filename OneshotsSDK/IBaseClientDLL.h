#pragma once
#include "ClientAndServerClass.h"
#include "IAppSystem.h"
#include "GlobalVars.h"

class IBaseClientDLL
{
public:
	virtual int              Connect(CreateInterfaceFn appSystemFactory, CGlobalVarsBase *pGlobals) = 0;
	virtual int              Disconnect(void) = 0;
	virtual int              Init(CreateInterfaceFn appSystemFactory, CGlobalVarsBase *pGlobals) = 0;
	virtual void             PostInit() = 0;
	virtual void             Shutdown(void) = 0;
	virtual void             LevelInitPreEntity(char const* pMapName) = 0;
	virtual void             LevelInitPostEntity() = 0;
	virtual void             LevelShutdown(void) = 0;
	virtual ClientClass*     GetAllClasses(void) = 0;
};