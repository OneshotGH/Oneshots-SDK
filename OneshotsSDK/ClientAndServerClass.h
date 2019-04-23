#pragma once
#include "Recv.h"

class ClientClass;
class IClientNetworkable;

typedef IClientNetworkable* (*CreateClientClassFn)(int entnum, int serialNum);
typedef IClientNetworkable* (*CreateEventFn)();

class ClientClass
{
public:

	CreateClientClassFn m_pCreateFn;
	CreateEventFn m_pCreateEventFn;
	char *m_pNetworkName;
	RecvTable *m_pRecvTable;
	ClientClass *m_pNext;
	int m_ClassID;
};
struct ServerClass
{
	const char					*m_pNetworkName;
	void*						*m_pTable;
	ServerClass					*m_pNext;
	int							m_ClassID;
	int							m_InstanceBaselineIndex;
};