#include "CBaseEntity.h"
#include "ClassIdManager.h"
#include "NetvarManager.h"

int CBaseEntity::GetHealth()
{
	return *(int*)((uintptr_t)this + Netvar->DT_BasePlayer.m_iHealth);
}

int CBaseEntity::GetFlags()
{
	return *(int*)((uintptr_t)this + Netvar->DT_BasePlayer.m_fFlags);
}

Vector CBaseEntity::GetOrigin()
{
	return *(Vector*)((uintptr_t)this + Netvar->DT_BaseEntity.m_vecOrigin);
}

QAngle CBaseEntity::GetEyeAngles()
{
	return *(QAngle*)((uintptr_t)this + Netvar->DT_CSPlayer.m_angEyeAngles);
}

bool CBaseEntity::IsPlayer()
{
	if (this->GetClientClass()->m_ClassID == ClassId->CCSPlayer)
		return true;
	return false;
}

bool CBaseEntity::IsWeapon()
{
	const int id = this->GetClientClass()->m_ClassID;
	if (id == ClassId->CBaseCombatWeapon ||
		id == ClassId->CAK47 ||
		id == ClassId->CSCAR17 ||
		id == ClassId->CWeaponAug ||
		id == ClassId->CWeaponAWP ||
		id == ClassId->CWeaponBaseItem ||
		id == ClassId->CWeaponBizon ||
		id == ClassId->CWeaponCSBase ||
		id == ClassId->CWeaponCSBaseGun ||
		id == ClassId->CWeaponElite ||
		id == ClassId->CWeaponFamas ||
		id == ClassId->CWeaponFiveSeven ||
		id == ClassId->CWeaponG3SG1 ||
		id == ClassId->CWeaponGalil ||
		id == ClassId->CWeaponGlock ||
		id == ClassId->CWeaponHKP2000 ||
		id == ClassId->CWeaponM249 ||
		id == ClassId->CWeaponM3 ||
		id == ClassId->CWeaponM4A1 ||
		id == ClassId->CWeaponMAC10 ||
		id == ClassId->CWeaponMag7 ||
		id == ClassId->CWeaponMP5Navy ||
		id == ClassId->CWeaponMP7 ||
		id == ClassId->CWeaponMP9 ||
		id == ClassId->CWeaponNegev ||
		id == ClassId->CWeaponNOVA ||
		id == ClassId->CWeaponP228 ||
		id == ClassId->CWeaponP250 ||
		id == ClassId->CWeaponP90 ||
		id == ClassId->CWeaponSawedoff ||
		id == ClassId->CWeaponSCAR20 ||
		id == ClassId->CWeaponScout ||
		id == ClassId->CWeaponSG550 ||
		id == ClassId->CWeaponSG552 ||
		id == ClassId->CWeaponSG556 ||
		id == ClassId->CWeaponSSG08 ||
		id == ClassId->CWeaponTaser ||
		id == ClassId->CWeaponTec9 ||
		id == ClassId->CWeaponTMP ||
		id == ClassId->CWeaponUMP45 ||
		id == ClassId->CWeaponUSP ||
		id == ClassId->CWeaponXM1014)
		return true;
	return false;
}

Vector CBaseEntity::GetEyePos()
{
	return GetOrigin() + GetEyeOffset();
}

int CBaseEntity::GetTeam()
{
	return *(int*)((uintptr_t)this + Netvar->DT_BaseEntity.m_iTeamNum);
}

Vector CBaseEntity::GetEyeOffset()
{
	return *(Vector*)((int)this + Netvar->DT_BasePlayer.m_vecViewOffset);
}
