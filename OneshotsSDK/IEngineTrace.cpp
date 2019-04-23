#include "IEngineTrace.h"
#include "ClassIdManager.h"
void IEngineTrace::TraceLine(Vector  vecAbsStart, Vector  vecAbsEnd, unsigned int mask, IHandleEntity * ignore, trace_t * ptr)
{
	Ray_t ray;
	ray.Init(vecAbsStart, vecAbsEnd);
	CTraceFilter filter;
	filter.pSkip = ignore;
	this->TraceRay(ray, mask, &filter, ptr);
}

bool CTraceFilterPlayersOnlySkipOne::ShouldHitEntity(IHandleEntity * pEntityHandle, int)
{
	return pEntityHandle != pEnt && ((IClientEntity*)pEntityHandle)->GetClientClass()->m_ClassID == ClassId->CCSPlayer;
}

CTraceFilterPlayersOnlySkipOne::CTraceFilterPlayersOnlySkipOne(IClientEntity * ent)
{
	pEnt = ent;
}

bool CTraceFilter::ShouldHitEntity(IHandleEntity * pEntityHandle, int)
{
	ClientClass* pEntCC = ((IClientEntity*)pEntityHandle)->GetClientClass();
	if (pEntCC && strcmp(ccIgnore, ""))
	{
		if (pEntCC->m_pNetworkName == ccIgnore)
			return false;
	}

	return !(pEntityHandle == pSkip);
}
