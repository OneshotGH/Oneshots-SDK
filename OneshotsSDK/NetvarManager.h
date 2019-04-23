#pragma once
#include "Interfaces.h"
#include <fstream>

class CNetvar
{
public:
	CNetvar();
	int DumpStructs();
	int DumpStructMembers();
	void DumpNetvars();
private:
	int GetOffset(const char * table, const char * netvar);
	int DumpRecursive(RecvTable * table);
public:
	std::fstream File;
	struct
	{
		int m_clrRender = 0;
		int m_vecOrigin = 0;
		int m_angRotation = 0;
		int moveparent = 0;
	}DT_TestTraceline;

	struct
	{
		int m_vecOrigin = 0;
		int m_nIndex = 0;
	}DT_TEWorldDecal;

	struct
	{
		int m_vecOrigin = 0;
		int m_vecDirection = 0;
		int m_nModelIndex = 0;
		int m_fNoise = 0;
		int m_nCount = 0;
		int m_nSpeed = 0;
	}DT_TESpriteSpray;

	struct
	{
		int m_vecOrigin = 0;
		int m_nModelIndex = 0;
		int m_fScale = 0;
		int m_nBrightness = 0;
	}DT_TESprite;

	struct
	{
		int m_nMagnitude = 0;
		int m_nTrailLength = 0;
		int m_vecDir = 0;
	}DT_TESparks;

	struct
	{
		int m_vecOrigin = 0;
		int m_nModelIndex = 0;
		int m_fScale = 0;
		int m_nFrameRate = 0;
	}DT_TESmoke;

	struct
	{
		int m_vecEnd = 0;
	}DT_TEShowLine;

	struct
	{
		int m_vecOrigin = 0;
		int m_angRotation = 0;
		int m_flDistance = 0;
		int m_nIndex = 0;
	}DT_TEProjectedDecal;

	struct
	{
		int m_nUniqueID = 0;
		int m_unAccountID = 0;
		int m_unTraceID = 0;
		int m_rtGcTime = 0;
		int m_vecEndPos = 0;
		int m_vecStart = 0;
		int m_vecRight = 0;
		int m_vecNormal = 0;
		int m_nEntity = 0;
		int m_nPlayer = 0;
		int m_nHitbox = 0;
		int m_nTintID = 0;
		int m_flCreationTime = 0;
		int m_nVersion = 0;
		int m_ubSignature = 0;
	}DT_FEPlayerDecal;

	struct
	{
		int m_vecOrigin = 0;
		int m_vecStart = 0;
		int m_vecRight = 0;
		int m_nEntity = 0;
		int m_nPlayer = 0;
		int m_nHitbox = 0;
	}DT_TEPlayerDecal;

	struct
	{
		int m_vecOrigin = 0;
		int m_angRotation = 0;
		int m_vecVelocity = 0;
		int m_nModelIndex = 0;
		int m_nFlags = 0;
		int m_nSkin = 0;
		int m_nEffects = 0;
		int m_clrRender = 0;
	}DT_TEPhysicsProp;

	struct
	{
		int m_vecOrigin = 0;
	}DT_TEParticleSystem;

	struct
	{
		int m_vecOrigin = 0;
		int m_vecAngles = 0;
		int m_flScale = 0;
		int m_nType = 0;
	}DT_TEMuzzleFlash;

	struct
	{
		int m_nModelIndex = 0;
		int m_nReversed = 0;
	}DT_TELargeFunnel;

	struct
	{
		int m_nPlayer = 0;
	}DT_TEKillPlayerAttachments;

	struct
	{
		int m_vecOrigin = 0;
		int m_vecNormal = 0;
		int m_iType = 0;
		int m_ucFlags = 0;
	}DT_TEImpact;

	struct
	{
		int m_vecOrigin = 0;
		int m_nModelIndex = 0;
		int m_fScale = 0;
		int m_fLife = 0;
		int m_nBrightness = 0;
	}DT_TEGlowSprite;

	struct
	{
		int m_vecOrigin = 0;
		int m_vecAngles = 0;
		int m_vecForce = 0;
		int m_vecForcePos = 0;
		int m_flWidth = 0;
		int m_flHeight = 0;
		int m_flShardSize = 0;
		int m_nSurfaceType = 0;
		int m_uchFrontColor = 0;
		int m_uchBackColor = 0;
	}DT_TEShatterSurface;

	struct
	{
		int m_vecOrigin = 0;
		int m_vecDirection = 0;
		int m_nEntity = 0;
		int m_nIndex = 0;
		int m_chMaterialType = 0;
	}DT_TEFootprintDecal;

	struct
	{
		int m_nEntity = 0;
		int m_nModelIndex = 0;
		int m_nDensity = 0;
		int m_nCurrent = 0;
	}DT_TEFizz;

	struct
	{
		int m_nModelIndex = 0;
		int m_fScale = 0;
		int m_nFrameRate = 0;
		int m_nFlags = 0;
		int m_vecNormal = 0;
		int m_chMaterialType = 0;
		int m_nRadius = 0;
		int m_nMagnitude = 0;
	}DT_TEExplosion;

	struct
	{
		int m_vecPos = 0;
		int m_vecDir = 0;
		int m_bExplosive = 0;
	}DT_TEEnergySplash;

	struct
	{
		int m_EffectData = 0;
	}DT_TEEffectDispatch;

	struct
	{
		int m_vecOrigin = 0;
		int r = 0;
		int g = 0;
		int b = 0;
		int exponent = 0;
		int m_fRadius = 0;
		int m_fTime = 0;
		int m_fDecay = 0;
	}DT_TEDynamicLight;

	struct
	{
		int m_vecOrigin = 0;
		int m_vecStart = 0;
		int m_nEntity = 0;
		int m_nHitbox = 0;
		int m_nIndex = 0;
	}DT_TEDecal;

	struct
	{
		int m_vecOrigin = 0;
		int m_vecVelocity = 0;
		int m_nModelIndex = 0;
		int m_nLifeTime = 0;
		int m_hOwner = 0;
	}DT_TEClientProjectile;

	struct
	{
		int m_vecMins = 0;
		int m_vecMaxs = 0;
		int m_nModelIndex = 0;
		int m_flWaterZ = 0;
		int m_nCount = 0;
		int m_fSpeed = 0;
	}DT_TEBubbleTrail;

	struct
	{
		int m_vecMins = 0;
		int m_vecMaxs = 0;
		int m_nModelIndex = 0;
		int m_fHeight = 0;
		int m_nCount = 0;
		int m_fSpeed = 0;
	}DT_TEBubbles;

	struct
	{
		int m_vecOrigin = 0;
		int m_nEntity = 0;
		int m_nIndex = 0;
	}DT_TEBSPDecal;

	struct
	{
		int m_vecOrigin = 0;
		int m_angRotation = 0;
		int m_vecSize = 0;
		int m_vecVelocity = 0;
		int m_nModelIndex = 0;
		int m_nRandomization = 0;
		int m_nCount = 0;
		int m_fTime = 0;
		int m_nFlags = 0;
	}DT_TEBreakModel;

	struct
	{
		int m_vecDirection = 0;
		int r = 0;
		int g = 0;
		int b = 0;
		int a = 0;
		int m_nAmount = 0;
	}DT_TEBloodStream;

	struct
	{
		int m_vecOrigin = 0;
		int m_vecDirection = 0;
		int r = 0;
		int g = 0;
		int b = 0;
		int a = 0;
		int m_nSprayModel = 0;
		int m_nDropModel = 0;
		int m_nSize = 0;
	}DT_TEBloodSprite;

	struct
	{
		int m_nPoints = 0;
		int m_vecPoints = 0;
	}DT_TEBeamSpline;

	struct
	{
		int m_vecCenter = 0;
		int m_flStartRadius = 0;
		int m_flEndRadius = 0;
	}DT_TEBeamRingPoint;

	struct
	{
		int m_nStartEntity = 0;
		int m_nEndEntity = 0;
	}DT_TEBeamRing;

	struct
	{
		int m_vecStartPoint = 0;
		int m_vecEndPoint = 0;
	}DT_TEBeamPoints;

	struct
	{
		int m_nStartEntity = 0;
		int m_nEndEntity = 0;
	}DT_TEBeamLaser;

	struct
	{
		int m_iEntIndex = 0;
	}DT_TEBeamFollow;

	struct
	{
		int m_nStartEntity = 0;
		int m_nEndEntity = 0;
	}DT_TEBeamEnts;

	struct
	{
		int m_nStartEntity = 0;
		int m_nEndEntity = 0;
		int m_vecStartPoint = 0;
		int m_vecEndPoint = 0;
	}DT_TEBeamEntPoint;

	struct
	{
		int m_nModelIndex = 0;
		int m_nHaloIndex = 0;
		int m_nStartFrame = 0;
		int m_nFrameRate = 0;
		int m_fLife = 0;
		int m_fWidth = 0;
		int m_fEndWidth = 0;
		int m_nFadeLength = 0;
		int m_fAmplitude = 0;
		int m_nSpeed = 0;
		int r = 0;
		int g = 0;
		int b = 0;
		int a = 0;
		int m_nFlags = 0;
	}DT_BaseBeam;

	struct
	{
		int m_vecPos = 0;
		int m_vecDir = 0;
	}DT_TEMetalSparks;

	struct
	{
		int m_SpreadSpeed = 0;
		int m_Speed = 0;
		int m_StartSize = 0;
		int m_EndSize = 0;
		int m_Rate = 0;
		int m_JetLength = 0;
		int m_bEmit = 0;
		int m_bFaceLeft = 0;
		int m_nType = 0;
		int m_spawnflags = 0;
		int m_flRollSpeed = 0;
	}DT_SteamJet;

	struct
	{
		int m_SpreadSpeed = 0;
		int m_Speed = 0;
		int m_StartSize = 0;
		int m_EndSize = 0;
		int m_Rate = 0;
		int m_JetLength = 0;
		int m_bEmit = 0;
		int m_flBaseSpread = 0;
		int m_flTwist = 0;
		int m_flRollSpeed = 0;
		int m_iMaterialModel = 0;
		int m_AmbientLight_m_vPos = 0;
		int m_AmbientLight_m_vColor = 0;
		int m_AmbientLight_m_flIntensity = 0;
		int m_DirLight_m_vPos = 0;
		int m_DirLight_m_vColor = 0;
		int m_DirLight_m_flIntensity = 0;
		int m_vWind = 0;
	}DT_SmokeStack;

	struct
	{
		int m_SpawnRate = 0;
		int m_Color = 0;
		int m_ParticleLifetime = 0;
		int m_StopEmitTime = 0;
		int m_MinSpeed = 0;
		int m_MaxSpeed = 0;
		int m_MinDirectedSpeed = 0;
		int m_MaxDirectedSpeed = 0;
		int m_StartSize = 0;
		int m_EndSize = 0;
		int m_SpawnRadius = 0;
		int m_bEmit = 0;
		int m_Opacity = 0;
	}DT_DustTrail;

	struct
	{
		int m_nAttachment = 0;
		int m_flLifetime = 0;
	}DT_FireTrail;

	struct
	{
		int m_flSpawnRate = 0;
		int m_vecEndColor = 0;
		int m_flParticleLifetime = 0;
		int m_flStartSize = 0;
		int m_flEndSize = 0;
		int m_flSpawnRadius = 0;
		int m_bEmit = 0;
	}DT_SporeTrail;

	struct
	{
		int m_flSpawnRate = 0;
		int m_flParticleLifetime = 0;
		int m_flStartSize = 0;
		int m_flEndSize = 0;
		int m_flSpawnRadius = 0;
		int m_bEmit = 0;
		int m_bDontRemove = 0;
	}DT_SporeExplosion;

	struct
	{
		int m_SpawnRate = 0;
		int m_StartColor = 0;
		int m_EndColor = 0;
		int m_ParticleLifetime = 0;
		int m_StopEmitTime = 0;
		int m_MinSpeed = 0;
		int m_MaxSpeed = 0;
		int m_StartSize = 0;
		int m_EndSize = 0;
		int m_SpawnRadius = 0;
		int m_bEmit = 0;
		int m_nAttachment = 0;
		int m_Opacity = 0;
		int m_bDamaged = 0;
		int m_flFlareScale = 0;
	}DT_RocketTrail;

	struct
	{
		int m_SpawnRate = 0;
		int m_StartColor = 0;
		int m_EndColor = 0;
		int m_ParticleLifetime = 0;
		int m_StopEmitTime = 0;
		int m_MinSpeed = 0;
		int m_MaxSpeed = 0;
		int m_MinDirectedSpeed = 0;
		int m_MaxDirectedSpeed = 0;
		int m_StartSize = 0;
		int m_EndSize = 0;
		int m_SpawnRadius = 0;
		int m_bEmit = 0;
		int m_nAttachment = 0;
		int m_Opacity = 0;
	}DT_SmokeTrail;

	struct
	{
		int m_hPlayer = 0;
		int m_nSpeed = 0;
		int m_nRPM = 0;
		int m_flThrottle = 0;
		int m_nBoostTimeLeft = 0;
		int m_nHasBoost = 0;
		int m_nScannerDisabledWeapons = 0;
		int m_nScannerDisabledVehicle = 0;
		int m_bEnterAnimOn = 0;
		int m_bExitAnimOn = 0;
		int m_bUnableToFire = 0;
		int m_vecEyeExitEndpoint = 0;
		int m_bHasGun = 0;
		int m_vecGunCrosshair = 0;
	}DT_PropVehicleDriveable;

	struct
	{
		int m_flSpawnTime = 0;
		int m_FadeStartTime = 0;
		int m_FadeEndTime = 0;
		int m_MinColor = 0;
		int m_MaxColor = 0;
		int m_CurrentStage = 0;
	}DT_ParticleSmokeGrenade;

	struct
	{
		int m_vOrigin = 0;
		int m_vDirection = 0;
	}DT_ParticleFire;

	struct
	{
		int m_nType = 0;
		int m_vecDirection = 0;
	}DT_TEGaussExplosion;

	struct
	{
		int m_targetPosition = 0;
		int m_controlPosition = 0;
		int m_scrollRate = 0;
		int m_flWidth = 0;
	}DT_QuadraticBeam;

	struct
	{
		int m_nDensity = 0;
		int m_nLifetime = 0;
		int m_nSpeed = 0;
		int m_bEmit = 0;
	}DT_Embers;

	struct
	{
		int m_EnvWindShared = 0;
	}DT_EnvWind;

	struct
	{
		int m_nPrecipType = 0;
	}DT_Precipitation;

	struct
	{
		int m_AttributeManager = 0;
		int m_OriginalOwnerXuidLow = 0;
		int m_OriginalOwnerXuidHigh = 0;
		int m_nFallbackPaintKit = 0;
		int m_nFallbackSeed = 0;
		int m_flFallbackWear = 0;
		int m_nFallbackStatTrak = 0;
	}DT_BaseAttributableItem;

	struct
	{
		int m_AttributeManager = 0;
		int m_OriginalOwnerXuidLow = 0;
		int m_OriginalOwnerXuidHigh = 0;
		int m_nFallbackPaintKit = 0;
		int m_nFallbackSeed = 0;
		int m_flFallbackWear = 0;
		int m_nFallbackStatTrak = 0;
	}DT_EconEntity;

	struct
	{
		int m_reloadState = 0;
	}DT_WeaponXM1014;

	struct
	{
		int m_fFireTime = 0;
	}DT_WeaponTaser;

	struct
	{
		int m_flUpgradeExpirationTime = 0;
		int m_vecLocalHexFlags = 0;
		int m_nContractKillGridIndex = 0;
		int m_nContractKillGridHighResIndex = 0;
		int m_bTabletReceptionIsBlocked = 0;
		int m_flScanProgress = 0;
		int m_flBootTime = 0;
		int m_flShowMapTime = 0;
		int m_vecNotificationIds = 0;
		int m_vecNotificationTimestamps = 0;
		int m_vecPlayerPositionHistory = 0;
		int m_nLastPurchaseIndex = 0;
	}DT_WeaponTablet;

	struct
	{
		int m_reloadState = 0;
	}DT_WeaponSawedoff;

	struct
	{
		int m_reloadState = 0;
	}DT_WeaponNOVA;

	struct
	{
		int m_flThrowAt = 0;
	}DT_WeaponMelee;

	struct
	{
		int m_reloadState = 0;
	}DT_WeaponM3;

	struct
	{
		int m_bPlayingUninterruptableAct = 0;
	}DT_WeaponFists;

	struct
	{
		int m_zoomLevel = 0;
		int m_iBurstShotsRemaining = 0;
	}DT_WeaponCSBaseGun;

	struct
	{
		int m_weaponMode = 0;
		int m_fAccuracyPenalty = 0;
		int m_fLastShotTime = 0;
		int m_iRecoilIndex = 0;
		int m_flRecoilIndex = 0;
		int m_hPrevOwner = 0;
		int m_bBurstMode = 0;
		int m_flPostponeFireReadyTime = 0;
		int m_bReloadVisuallyComplete = 0;
		int m_bSilencerOn = 0;
		int m_flDoneSwitchingSilencer = 0;
		int m_iOriginalTeamNumber = 0;
		int m_iIronSightMode = 0;
	}DT_WeaponCSBase;

	struct
	{
		int m_bStartedArming = 0;
		int m_bBombPlacedAnimation = 0;
		int m_fArmedTime = 0;
		int m_bShowC4LED = 0;
		int m_bIsPlantingViaUse = 0;
	}DT_WeaponC4;

	struct
	{
		int m_bShouldExplode = 0;
		int m_weaponThatThrewMe = 0;
		int m_nParentBoneIndex = 0;
		int m_vecParentBonePos = 0;
	}DT_BreachChargeProjectile;

	struct
	{
		int m_bRedraw = 0;
	}DT_WeaponBaseItem;

	struct
	{
		int m_bRedraw = 0;
		int m_bIsHeldByPlayer = 0;
		int m_bPinPulled = 0;
		int m_fThrowTime = 0;
		int m_bLoopingSoundPlaying = 0;
		int m_flThrowStrength = 0;
	}DT_BaseCSGrenade;

	struct
	{
		int m_bDidSmokeEffect = 0;
		int m_nSmokeEffectTickBegin = 0;
	}DT_SmokeGrenadeProjectile;

	struct
	{
		int m_bIsIncGrenade = 0;
	}DT_MolotovProjectile;

	struct
	{
		int m_OwningPlayer = 0;
		int m_KillingPlayer = 0;
	}DT_ItemDogtags;

	struct
	{
		int m_bRenderInPSPM = 0;
		int m_bRenderInTablet = 0;
		int m_iHealth = 0;
		int m_iMaxHealth = 0;
	}DT_PhysPropLootCrate;

	struct
	{
		int m_flFlightSpeed = 0;
		int m_flLaunchTime = 0;
		int m_vecParabolaDirection = 0;
		int m_flFlightTime = 0;
		int m_flWorldEnterTime = 0;
		int m_flInitialZSpeed = 0;
		int m_flZAcceleration = 0;
		int m_flHorizSpeed = 0;
		int m_bLaunchedFromWithinWorld = 0;
		int m_vecImpactPosition = 0;
		int m_vecStartPosition = 0;
		int m_vecEnterWorldPosition = 0;
		int m_vecDirection = 0;
		int m_vecStartAngles = 0;
		int m_vecSkyboxOrigin = 0;
		int m_flSkyboxScale = 0;
		int m_bInSkybox = 0;
		int m_bDoImpactEffects = 0;
		int m_bLanded = 0;
		int m_hSkyboxCopy = 0;
		int m_nMyZoneIndex = 0;
		int m_vecOrigin = 0;
	}DT_EnvGasCanister;

	struct
	{
		int m_vecAttentionTarget = 0;
		int m_vecTargetOffset = 0;
		int m_iHealth = 0;
		int m_bHasTarget = 0;
	}DT_Dronegun;

	struct
	{
		int m_vecOrigin = 0;
		int m_hCallingPlayer = 0;
	}DT_ParadropChopper;

	struct
	{
		int m_vecOrigin = 0;
	}DT_SurvivalSpawnChopper;

	struct
	{
		int m_bBrokenOpen = 0;
		int m_flRadius = 0;
	}DT_BRC4Target;

	struct
	{
		int m_flRadius = 0;
		int m_szLocToken = 0;
	}DT_InfoMapRegion;

	struct
	{
		int m_fireXDelta = 0;
		int m_fireYDelta = 0;
		int m_fireZDelta = 0;
		int m_bFireIsBurning = 0;
		int m_fireCount = 0;
	}DT_Inferno;

	struct
	{
		int m_jumpedThisFrame = 0;
		int m_leader = 0;
	}DT_CChicken;

	struct
	{
		int m_hMoveToThisEntity = 0;
		int m_hDeliveryCargo = 0;
	}DT_Drone;

	struct
	{
		int m_source = 0;
		int m_destination = 0;
	}DT_FootstepControl;

	struct
	{
		int cs_gamerules_data = 0;
	}DT_CSGameRulesProxy;

	struct
	{
		int m_vecOrigin = 0;
		int m_iPlayer = 0;
		int m_option = 0;
	}DT_TEPlantBomb;

	struct
	{
		int m_vecOrigin = 0;
		int m_vecAngles = 0;
		int m_iWeaponID = 0;
		int m_weapon = 0;
		int m_iMode = 0;
		int m_iSeed = 0;
		int m_iPlayer = 0;
		int m_fInaccuracy = 0;
		int m_fSpread = 0;
		int m_nItemDefIndex = 0;
		int m_iSoundType = 0;
		int m_flRecoilIndex = 0;
	}DT_TEFireBullets;

	struct
	{
		int m_iAttachToClient = 0;
	}DT_TERadioIcon;

	struct
	{
		int m_bBombTicking = 0;
		int m_nBombSite = 0;
		int m_flC4Blow = 0;
		int m_flTimerLength = 0;
		int m_flDefuseLength = 0;
		int m_flDefuseCountDown = 0;
		int m_bBombDefused = 0;
		int m_hBombDefuser = 0;
	}DT_PlantedC4;

	struct
	{
		int m_iPlayerC4 = 0;
		int m_iPlayerVIP = 0;
		int m_bHostageAlive = 0;
		int m_isHostageFollowingSomeone = 0;
		int m_iHostageEntityIDs = 0;
		int m_bombsiteCenterA = 0;
		int m_bombsiteCenterB = 0;
		int m_hostageRescueX = 0;
		int m_hostageRescueY = 0;
		int m_hostageRescueZ = 0;
		int m_iMVPs = 0;
		int m_iArmor = 0;
		int m_bHasHelmet = 0;
		int m_bHasDefuser = 0;
		int m_iScore = 0;
		int m_iCompetitiveRanking = 0;
		int m_iCompetitiveWins = 0;
		int m_iCompetitiveRankType = 0;
		int m_iCompTeammateColor = 0;
		int m_iLifetimeStart = 0;
		int m_iLifetimeEnd = 0;
		int m_bControllingBot = 0;
		int m_iControlledPlayer = 0;
		int m_iControlledByPlayer = 0;
		int m_iBotDifficulty = 0;
		int m_szClan = 0;
		int m_iTotalCashSpent = 0;
		int m_iGunGameLevel = 0;
		int m_iCashSpentThisRound = 0;
		int m_nEndMatchNextMapVotes = 0;
		int m_bEndMatchNextMapAllVoted = 0;
		int m_nActiveCoinRank = 0;
		int m_nMusicID = 0;
		int m_nPersonaDataPublicLevel = 0;
		int m_nPersonaDataPublicCommendsLeader = 0;
		int m_nPersonaDataPublicCommendsTeacher = 0;
		int m_nPersonaDataPublicCommendsFriendly = 0;
		int m_iMatchStats_Kills_Total = 0;
		int m_iMatchStats_5k_Total = 0;
		int m_iMatchStats_4k_Total = 0;
		int m_iMatchStats_3k_Total = 0;
		int m_iMatchStats_Damage_Total = 0;
		int m_iMatchStats_EquipmentValue_Total = 0;
		int m_iMatchStats_KillReward_Total = 0;
		int m_iMatchStats_LiveTime_Total = 0;
		int m_iMatchStats_Deaths_Total = 0;
		int m_iMatchStats_Assists_Total = 0;
		int m_iMatchStats_HeadShotKills_Total = 0;
		int m_iMatchStats_Objective_Total = 0;
		int m_iMatchStats_CashEarned_Total = 0;
		int m_iMatchStats_UtilityDamage_Total = 0;
		int m_iMatchStats_EnemiesFlashed_Total = 0;
	}DT_CSPlayerResource;

	struct
	{
		int cslocaldata = 0;
		int csnonlocaldata = 0;
		int csteamdata = 0;
		int m_angEyeAngles = 0;
		int m_iAddonBits = 0;
		int m_iPrimaryAddon = 0;
		int m_iSecondaryAddon = 0;
		int m_iThrowGrenadeCounter = 0;
		int m_bWaitForNoAttack = 0;
		int m_bIsRespawningForDMBonus = 0;
		int m_iPlayerState = 0;
		int m_iAccount = 0;
		int m_iStartAccount = 0;
		int m_totalHitsOnServer = 0;
		int m_bInBombZone = 0;
		int m_bInBuyZone = 0;
		int m_bInNoDefuseArea = 0;
		int m_bKilledByTaser = 0;
		int m_iMoveState = 0;
		int m_iClass = 0;
		int m_ArmorValue = 0;
		int m_bHasDefuser = 0;
		int m_bNightVisionOn = 0;
		int m_bHasNightVision = 0;
		int m_bInHostageRescueZone = 0;
		int m_bIsDefusing = 0;
		int m_bIsGrabbingHostage = 0;
		int m_iBlockingUseActionInProgress = 0;
		int m_bIsScoped = 0;
		int m_bIsWalking = 0;
		int m_nIsAutoMounting = 0;
		int m_bResumeZoom = 0;
		int m_fImmuneToGunGameDamageTime = 0;
		int m_bGunGameImmunity = 0;
		int m_bHasMovedSinceSpawn = 0;
		int m_bMadeFinalGunGameProgressiveKill = 0;
		int m_iGunGameProgressiveWeaponIndex = 0;
		int m_iNumGunGameTRKillPoints = 0;
		int m_iNumGunGameKillsWithCurrentWeapon = 0;
		int m_iNumRoundKills = 0;
		int m_fMolotovUseTime = 0;
		int m_fMolotovDamageTime = 0;
		int m_szArmsModel = 0;
		int m_hCarriedHostage = 0;
		int m_hCarriedHostageProp = 0;
		int m_bIsRescuing = 0;
		int m_flGroundAccelLinearFracLastTime = 0;
		int m_bCanMoveDuringFreezePeriod = 0;
		int m_isCurrentGunGameLeader = 0;
		int m_isCurrentGunGameTeamLeader = 0;
		int m_flGuardianTooFarDistFrac = 0;
		int m_flDetectedByEnemySensorTime = 0;
		int m_bIsPlayerGhost = 0;
		int m_iMatchStats_Kills = 0;
		int m_iMatchStats_Damage = 0;
		int m_iMatchStats_EquipmentValue = 0;
		int m_iMatchStats_MoneySaved = 0;
		int m_iMatchStats_KillReward = 0;
		int m_iMatchStats_LiveTime = 0;
		int m_iMatchStats_Deaths = 0;
		int m_iMatchStats_Assists = 0;
		int m_iMatchStats_HeadShotKills = 0;
		int m_iMatchStats_Objective = 0;
		int m_iMatchStats_CashEarned = 0;
		int m_iMatchStats_UtilityDamage = 0;
		int m_iMatchStats_EnemiesFlashed = 0;
		int m_rank = 0;
		int m_unMusicID = 0;
		int m_bHasHelmet = 0;
		int m_bHasHeavyArmor = 0;
		int m_nHeavyAssaultSuitCooldownRemaining = 0;
		int m_flFlashDuration = 0;
		int m_flFlashMaxAlpha = 0;
		int m_iProgressBarDuration = 0;
		int m_flProgressBarStartTime = 0;
		int m_hRagdoll = 0;
		int m_cycleLatch = 0;
		int m_unCurrentEquipmentValue = 0;
		int m_unRoundStartEquipmentValue = 0;
		int m_unFreezetimeEndEquipmentValue = 0;
		int m_bIsControllingBot = 0;
		int m_bHasControlledBotThisRound = 0;
		int m_bCanControlObservedBot = 0;
		int m_iControlledBotEntIndex = 0;
		int m_vecAutomoveTargetEnd = 0;
		int m_flAutoMoveStartTime = 0;
		int m_flAutoMoveTargetTime = 0;
		int m_bIsAssassinationTarget = 0;
		int m_bHud_MiniScoreHidden = 0;
		int m_bHud_RadarHidden = 0;
		int m_nLastKillerIndex = 0;
		int m_nLastConcurrentKilled = 0;
		int m_nDeathCamMusic = 0;
		int m_bIsHoldingLookAtWeapon = 0;
		int m_bIsLookingAtWeapon = 0;
		int m_iNumRoundKillsHeadshots = 0;
		int m_unTotalRoundDamageDealt = 0;
		int m_flLowerBodyYawTarget = 0;
		int m_bStrafing = 0;
		int m_flThirdpersonRecoil = 0;
		int m_bHideTargetID = 0;
		int m_bHasParachute = 0;
		int m_bIsSpawnRappelling = 0;
		int m_vecSpawnRappellingRopeOrigin = 0;
		int m_nSurvivalTeam = 0;
		int m_hSurvivalAssassinationTarget = 0;
		int m_flHealthShotBoostExpirationTime = 0;
	}DT_CSPlayer;

	struct
	{
		int m_vecOrigin = 0;
		int m_vecRagdollOrigin = 0;
		int m_hPlayer = 0;
		int m_nModelIndex = 0;
		int m_nForceBone = 0;
		int m_vecForce = 0;
		int m_vecRagdollVelocity = 0;
		int m_iDeathPose = 0;
		int m_iDeathFrame = 0;
		int m_iTeamNum = 0;
		int m_bClientSideAnimation = 0;
		int m_flDeathYaw = 0;
		int m_flAbsYaw = 0;
	}DT_CSRagdoll;

	struct
	{
		int m_hPlayer = 0;
		int m_iEvent = 0;
		int m_nData = 0;
	}DT_TEPlayerAnimEvent;

	struct
	{
		int m_isRescued = 0;
		int m_jumpedThisFrame = 0;
		int m_iHealth = 0;
		int m_iMaxHealth = 0;
		int m_lifeState = 0;
		int m_fFlags = 0;
		int m_nHostageState = 0;
		int m_flRescueStartTime = 0;
		int m_flGrabSuccessTime = 0;
		int m_flDropStartTime = 0;
		int m_vel = 0;
		int m_leader = 0;
	}DT_CHostage;

	struct
	{
		int m_vInitialVelocity = 0;
		int m_nBounces = 0;
	}DT_BaseCSGrenadeProjectile;

	struct
	{
		int m_Handle = 0;
		int m_bSendHandle = 0;
	}DT_HandleTest;

	struct
	{
		int teamplayroundbased_gamerules_data = 0;
	}DT_TeamplayRoundBasedRulesProxy;

	struct
	{
		int m_flLifeTime = 0;
		int m_flStartWidth = 0;
		int m_flEndWidth = 0;
		int m_flStartWidthVariance = 0;
		int m_flTextureRes = 0;
		int m_flMinFadeLength = 0;
		int m_vecSkyboxOrigin = 0;
		int m_flSkyboxScale = 0;
	}DT_SpriteTrail;

	struct
	{
		int m_hAttachedToEntity = 0;
		int m_nAttachment = 0;
		int m_flScaleTime = 0;
		int m_flSpriteScale = 0;
		int m_flSpriteFramerate = 0;
		int m_flGlowProxySize = 0;
		int m_flHDRColorScale = 0;
		int m_flFrame = 0;
		int m_flBrightnessTime = 0;
		int m_nBrightness = 0;
		int m_bWorldSpaceScale = 0;
	}DT_Sprite;

	struct
	{
		int m_boneIndexAttached = 0;
		int m_ragdollAttachedObjectIndex = 0;
		int m_attachmentPointBoneSpace = 0;
		int m_attachmentPointRagdollSpace = 0;
	}DT_Ragdoll_Attached;

	struct
	{
		int m_ragAngles = 0;
		int m_ragPos = 0;
		int m_hUnragdoll = 0;
		int m_flBlendWeight = 0;
		int m_nOverlaySequence = 0;
	}DT_Ragdoll;

	struct
	{
		int m_flDisplayValue = 0;
	}DT_PropCounter;

	struct
	{
		int m_hProps = 0;
		int m_chPoseIndex = 0;
		int m_bPoseValueParity = 0;
		int m_fPoseValue = 0;
		int m_fInterpolationTime = 0;
		int m_bInterpolationWrap = 0;
		int m_fCycleFrequency = 0;
		int m_nFModType = 0;
		int m_fFModTimeOffset = 0;
		int m_fFModRate = 0;
		int m_fFModAmplitude = 0;
	}DT_PoseController;

	struct
	{
		int m_flGrassBurnClearTime = 0;
	}DT_GrassBurn;

	struct
	{
		int m_vecPlayerMountPositionTop = 0;
		int m_vecPlayerMountPositionBottom = 0;
		int m_vecLadderDir = 0;
		int m_bFakeLadder = 0;
	}DT_FuncLadder;

	struct
	{
		int m_iEntity = 0;
	}DT_TEFoundryHelpers;

	struct
	{
		int m_flFadeStartDist = 0;
		int m_flFadeEndDist = 0;
	}DT_DetailController;

	struct
	{
		int m_vecDangerZoneOriginStartedAt = 0;
		int m_flBombLaunchTime = 0;
		int m_flExtraRadius = 0;
		int m_flExtraRadiusStartTime = 0;
		int m_flExtraRadiusTotalLerpTime = 0;
		int m_nDropOrder = 0;
		int m_iWave = 0;
	}DT_DangerZone;

	struct
	{
		int m_bDangerZoneControllerEnabled = 0;
		int m_flStartTime = 0;
		int m_flFinalExpansionTime = 0;
		int m_vecEndGameCircleStart = 0;
		int m_vecEndGameCircleEnd = 0;
		int m_DangerZones = 0;
		int m_flWaveEndTimes = 0;
		int m_hTheFinalZone = 0;
	}DT_DangerZoneController;

	struct
	{
		int m_bEnabled = 0;
		int m_szDisplayText = 0;
		int m_szDisplayTextOption = 0;
		int m_szFont = 0;
		int m_iTextPanelWidth = 0;
		int m_clrText = 0;
	}DT_WorldVguiText;

	struct
	{
		int m_flWaveHeight = 0;
		int m_WorldMins = 0;
		int m_WorldMaxs = 0;
		int m_bStartDark = 0;
		int m_flMaxOccludeeArea = 0;
		int m_flMinOccluderArea = 0;
		int m_flMaxPropScreenSpaceWidth = 0;
		int m_flMinPropScreenSpaceWidth = 0;
		int m_iszDetailSpriteMaterial = 0;
		int m_bColdWorld = 0;
		int m_iTimeOfDay = 0;
	}DT_World;

	struct
	{
		int m_flCheapWaterStartDistance = 0;
		int m_flCheapWaterEndDistance = 0;
	}DT_WaterLODControl;

	struct
	{
		int m_iActiveIssueIndex = 0;
		int m_iOnlyTeamToVote = 0;
		int m_nVoteOptionCount = 0;
		int m_nPotentialVotes = 0;
		int m_bIsYesNoVote = 0;
	}DT_VoteController;

	struct
	{
		int m_flWidth = 0;
		int m_flHeight = 0;
		int m_fScreenFlags = 0;
		int m_nPanelName = 0;
		int m_nAttachmentIndex = 0;
		int m_nOverlayMaterial = 0;
		int m_hPlayerOwner = 0;
	}DT_VGuiScreen;

	struct
	{
		int m_bHeadlightIsOn = 0;
	}DT_PropJeep;

	struct
	{
		int m_hPlayer = 0;
		int m_bEnterAnimOn = 0;
		int m_bExitAnimOn = 0;
		int m_bForceEyesToAttachment = 0;
		int m_vecEyeExitEndpoint = 0;
		int m_vehicleView_bClampEyeAngles = 0;
		int m_vehicleView_flPitchCurveZero = 0;
		int m_vehicleView_flPitchCurveLinear = 0;
		int m_vehicleView_flRollCurveZero = 0;
		int m_vehicleView_flRollCurveLinear = 0;
		int m_vehicleView_flFOV = 0;
		int m_vehicleView_flYawMin = 0;
		int m_vehicleView_flYawMax = 0;
		int m_vehicleView_flPitchMin = 0;
		int m_vehicleView_flPitchMax = 0;
	}DT_PropVehicleChoreoGeneric;

	struct
	{
		int m_nSoundOperator = 0;
	}DT_TriggerSoundOperator;

	struct
	{
		int m_bClientSidePredicted = 0;
		int m_spawnflags = 0;
	}DT_BaseTrigger;

	struct
	{
		int blah = 0;
	}DT_ProxyToggle;

	struct
	{
		int m_SoundName = 0;
		int m_iszSpriteName = 0;
	}DT_Tesla;

	struct
	{
		int m_iTimerToShowInHUD = 0;
		int m_iStopWatchTimer = 0;
		int m_iNumControlPoints = 0;
		int m_bPlayingMiniRounds = 0;
		int m_bControlPointsReset = 0;
		int m_iUpdateCapHudParity = 0;
		int m_vCPPositions = 0;
		int m_bCPIsVisible = 0;
		int m_flLazyCapPerc = 0;
		int m_iTeamIcons = 0;
		int m_iTeamOverlays = 0;
		int m_iTeamReqCappers = 0;
		int m_flTeamCapTime = 0;
		int m_iPreviousPoints = 0;
		int m_bTeamCanCap = 0;
		int m_iTeamBaseIcons = 0;
		int m_iBaseControlPoints = 0;
		int m_bInMiniRound = 0;
		int m_iWarnOnCap = 0;
		int m_iszWarnSound = 0;
		int m_flPathDistance = 0;
		int m_iNumTeamMembers = 0;
		int m_iCappingTeam = 0;
		int m_iTeamInZone = 0;
		int m_bBlocked = 0;
		int m_iOwner = 0;
		int m_pszCapLayoutInHUD = 0;
	}DT_BaseTeamObjectiveResource;

	struct
	{
		int m_iTeamNum = 0;
		int m_bSurrendered = 0;
		int m_scoreTotal = 0;
		int m_scoreFirstHalf = 0;
		int m_scoreSecondHalf = 0;
		int m_scoreOvertime = 0;
		int m_iClanID = 0;
		int m_szTeamname = 0;
		int m_szClanTeamname = 0;
		int m_szTeamFlagImage = 0;
		int m_szTeamLogoImage = 0;
		int m_szTeamMatchStat = 0;
		int m_nGGLeaderEntIndex_CT = 0;
		int m_nGGLeaderEntIndex_T = 0;
		int m_numMapVictories = 0;
		int player_array_element = 0;
		int player_array = 0;
	}DT_Team;

	struct
	{
		int m_shadowDirection = 0;
		int m_bEnabled = 0;
		int m_TextureName = 0;
		int m_LightColor = 0;
		int m_flColorTransitionTime = 0;
		int m_flSunDistance = 0;
		int m_flFOV = 0;
		int m_flNearZ = 0;
		int m_flNorthOffset = 0;
		int m_bEnableShadows = 0;
	}DT_SunlightShadowControl;

	struct
	{
		int m_clrRender = 0;
		int m_clrOverlay = 0;
		int m_vDirection = 0;
		int m_bOn = 0;
		int m_nSize = 0;
		int m_nOverlaySize = 0;
		int m_nMaterial = 0;
		int m_nOverlayMaterial = 0;
		int HDRColorScale = 0;
		int glowDistanceScale = 0;
	}DT_Sun;

	struct
	{
		int m_bMeasurePerf = 0;
		int m_bDisplayPerf = 0;
	}DT_ParticlePerformanceMonitor;

	struct
	{
		int m_flLightScale = 0;
		int m_Radius = 0;
	}DT_SpotlightEnd;

	struct
	{
		int m_vecOrigin = 0;
		int m_minFalloff = 0;
		int m_maxFalloff = 0;
		int m_flCurWeight = 0;
		int m_bEnabled = 0;
	}DT_SpatialEntity;

	struct
	{
		int m_bEnabled = 0;
		int m_szDisplayText = 0;
		int m_szSlideshowDirectory = 0;
		int m_chCurrentSlideLists = 0;
		int m_fMinSlideTime = 0;
		int m_fMaxSlideTime = 0;
		int m_iCycleType = 0;
		int m_bNoListRepeats = 0;
	}DT_SlideshowDisplay;

	struct
	{
		int m_shadowDirection = 0;
		int m_shadowColor = 0;
		int m_flShadowMaxDist = 0;
		int m_bDisableShadows = 0;
		int m_bEnableLocalLightShadows = 0;
	}DT_ShadowControl;

	struct
	{
		int m_nSceneStringIndex = 0;
		int m_bIsPlayingBack = 0;
		int m_bPaused = 0;
		int m_bMultiplayer = 0;
		int m_flForceClientTime = 0;
		int m_hActorList = 0;
	}DT_SceneEntity;

	struct
	{
		int m_nChangeCount = 0;
		int m_iRopeMaterialModelIndex = 0;
		int m_hStartPoint = 0;
		int m_hEndPoint = 0;
		int m_iStartAttachment = 0;
		int m_iEndAttachment = 0;
		int m_fLockedPoints = 0;
		int m_Slack = 0;
		int m_RopeLength = 0;
		int m_RopeFlags = 0;
		int m_TextureScale = 0;
		int m_nSegments = 0;
		int m_bConstrainBetweenEndpoints = 0;
		int m_Subdiv = 0;
		int m_Width = 0;
		int m_flScrollSpeed = 0;
		int m_vecOrigin = 0;
		int moveparent = 0;
		int m_iParentAttachment = 0;
		int m_iDefaultRopeMaterialModelIndex = 0;
		int m_nMinCPULevel = 0;
		int m_nMaxCPULevel = 0;
		int m_nMinGPULevel = 0;
		int m_nMaxGPULevel = 0;
	}DT_RopeKeyframe;

	struct
	{
		int m_iPhysicsMode = 0;
		int m_fMass = 0;
		int m_collisionMins = 0;
		int m_collisionMaxs = 0;
	}DT_PhysicsPropMultiplayer;

	struct
	{
		int m_iPhysicsMode = 0;
		int m_fMass = 0;
	}DT_PhysBoxMultiplayer;

	struct
	{
		int m_bUseHitboxesForRenderBox = 0;
		int m_flGlowMaxDist = 0;
		int m_bShouldGlow = 0;
		int m_clrGlow = 0;
		int m_nGlowStyle = 0;
	}DT_DynamicProp;

	struct
	{
		int m_bEnabled = 0;
		int m_fVisibleTime = 0;
		int m_fRechargeTime = 0;
	}DT_Prop_Hallucination;

	struct
	{
		int m_flPostProcessParameters = 0;
		int m_bMaster = 0;
	}DT_PostProcessController;

	struct
	{
		int m_szText = 0;
		int m_flTextSize = 0;
		int m_textColor = 0;
	}DT_PointWorldText;

	struct
	{
		int m_bActive = 0;
		int m_flStartTime = 0;
		int m_iszCommentaryFile = 0;
		int m_iszCommentaryFileNoHDR = 0;
		int m_iszSpeakers = 0;
		int m_iNodeNumber = 0;
		int m_iNodeNumberMax = 0;
		int m_hViewPosition = 0;
	}DT_PointCommentaryNode;

	struct
	{
		int m_FOV = 0;
		int m_Resolution = 0;
		int m_bFogEnable = 0;
		int m_FogColor = 0;
		int m_flFogStart = 0;
		int m_flFogEnd = 0;
		int m_flFogMaxDensity = 0;
		int m_bActive = 0;
		int m_bUseScreenAspectRatio = 0;
	}DT_PointCamera;

	struct
	{
		int m_iPing = 0;
		int m_iKills = 0;
		int m_iAssists = 0;
		int m_iDeaths = 0;
		int m_bConnected = 0;
		int m_iTeam = 0;
		int m_iPendingTeam = 0;
		int m_bAlive = 0;
		int m_iHealth = 0;
		int m_iCoachingTeam = 0;
	}DT_PlayerResource;

	struct
	{
		int m_flStartScale = 0;
		int m_flScale = 0;
		int m_flScaleTime = 0;
		int m_nFlags = 0;
		int m_nPlasmaModelIndex = 0;
		int m_nPlasmaModelIndex2 = 0;
		int m_nGlowModelIndex = 0;
	}DT_Plasma;

	struct
	{
		int m_bAwake = 0;
		int m_spawnflags = 0;
	}DT_PhysicsProp;

	struct
	{
		int m_hInitBaseAnimating = 0;
		int m_bShatter = 0;
		int m_nShatterFlags = 0;
		int m_vShatterPosition = 0;
		int m_vShatterForce = 0;
	}DT_StatueProp;

	struct
	{
		int m_mass = 0;
	}DT_PhysBox;

	struct
	{
		int m_vecOrigin = 0;
		int m_fEffects = 0;
		int m_hOwnerEntity = 0;
		int moveparent = 0;
		int m_iParentAttachment = 0;
		int m_angRotation = 0;
		int m_iEffectIndex = 0;
		int m_bActive = 0;
		int m_nStopType = 0;
		int m_flStartTime = 0;
		int m_szSnapshotFileName = 0;
		int m_vServerControlPoints = 0;
		int m_iServerControlPointAssignments = 0;
		int m_hControlPointEnts = 0;
		int m_iControlPointParents = 0;
	}DT_ParticleSystem;

	struct
	{
		int m_bEnabled = 0;
		int m_bLooping = 0;
		int m_szMovieFilename = 0;
		int m_szGroupName = 0;
		int m_bStretchToFill = 0;
		int m_bForcedSlave = 0;
		int m_bUseCustomUVs = 0;
		int m_flUMin = 0;
		int m_flUMax = 0;
		int m_flVMin = 0;
		int m_flVMax = 0;
	}DT_MovieDisplay;

	struct
	{
		int m_szMaterialName = 0;
		int m_szMaterialVar = 0;
		int m_szMaterialVarValue = 0;
		int m_iFrameStart = 0;
		int m_iFrameEnd = 0;
		int m_bWrap = 0;
		int m_flFramerate = 0;
		int m_bNewAnimCommandsSemaphore = 0;
		int m_flFloatLerpStartValue = 0;
		int m_flFloatLerpEndValue = 0;
		int m_flFloatLerpTransitionTime = 0;
		int m_bFloatLerpWrap = 0;
		int m_nModifyMode = 0;
	}DT_MaterialModifyControl;

	struct
	{
		int m_clrRender = 0;
		int m_nHorizontalSize = 0;
		int m_nVerticalSize = 0;
		int m_nMinDist = 0;
		int m_nMaxDist = 0;
		int m_nOuterMaxDist = 0;
		int m_spawnflags = 0;
		int m_vecOrigin = 0;
		int m_angRotation = 0;
		int moveparent = 0;
		int m_flGlowProxySize = 0;
		int HDRColorScale = 0;
	}DT_LightGlow;

	struct
	{
		int m_nArmorValue = 0;
		int m_bIsHeavyAssaultSuit = 0;
	}DT_ItemAssaultSuitUseable;

	struct
	{
		int m_bShouldGlow = 0;
	}DT_Item;

	struct
	{
		int m_iTextureFrameIndex = 0;
		int m_iOverlayID = 0;
	}DT_InfoOverlayAccessor;

	struct
	{
		int m_Color1 = 0;
		int m_Color2 = 0;
		int m_MaterialName = 0;
		int m_ParticleDrawWidth = 0;
		int m_ParticleSpacingDistance = 0;
		int m_DensityRampSpeed = 0;
		int m_RotationSpeed = 0;
		int m_MovementSpeed = 0;
		int m_Density = 0;
		int m_maxDrawDistance = 0;
		int m_spawnflags = 0;
		int m_Collision = 0;
	}DT_FuncSmokeVolume;

	struct
	{
		int m_vecOrigin = 0;
		int m_angRotation = 0;
		int m_flSimulationTime = 0;
	}DT_FuncRotating;

	struct
	{
		int m_bActive = 0;
		int m_nOccluderIndex = 0;
	}DT_FuncOccluder;

	struct
	{
		int m_vecVelocity = 0;
		int m_fFlags = 0;
	}DT_FuncMoveLinear;

	struct
	{
		int m_nDisappearMinDist = 0;
		int m_nDisappearMaxDist = 0;
	}DT_Func_LOD;

	struct
	{
		int m_flSize = 0;
		int m_flSpeed = 0;
		int m_vecDirection = 0;
	}DT_TEDust;

	struct
	{
		int m_Color = 0;
		int m_SpawnRate = 0;
		int m_flSizeMin = 0;
		int m_flSizeMax = 0;
		int m_LifetimeMin = 0;
		int m_LifetimeMax = 0;
		int m_DustFlags = 0;
		int m_SpeedMax = 0;
		int m_DistMax = 0;
		int m_nModelIndex = 0;
		int m_FallSpeed = 0;
		int m_bAffectedByWind = 0;
		int m_Collision = 0;
	}DT_Func_Dust;

	struct
	{
		int m_flConveyorSpeed = 0;
	}DT_FuncConveyor;

	struct
	{
		int m_nNumWide = 0;
		int m_nNumHigh = 0;
		int m_flPanelWidth = 0;
		int m_flPanelHeight = 0;
		int m_vNormal = 0;
		int m_vCorner = 0;
		int m_bIsBroken = 0;
		int m_nSurfaceType = 0;
		int m_RawPanelBitVec = 0;
	}DT_BreakableSurface;

	struct
	{
		int m_flFadeStartDist = 0;
		int m_flFadeDist = 0;
		int m_flTranslucencyLimit = 0;
		int m_iBackgroundModelIndex = 0;
	}DT_FuncAreaPortalWindow;

	struct
	{
		int m_poolOrigin = 0;
		int m_x = 0;
		int m_y = 0;
		int m_z = 0;
		int m_angle = 0;
		int m_nModelIndex = 0;
		int m_lifeState = 0;
		int m_waterLevel = 0;
	}DT_CFish;

	struct
	{
		int m_flStartScale = 0;
		int m_flScale = 0;
		int m_flScaleTime = 0;
		int m_nFlags = 0;
		int m_nFlameModelIndex = 0;
		int m_nFlameFromAboveModelIndex = 0;
	}DT_FireSmoke;

	struct
	{
		int m_bUseCustomAutoExposureMin = 0;
		int m_bUseCustomAutoExposureMax = 0;
		int m_bUseCustomBloomScale = 0;
		int m_flCustomAutoExposureMin = 0;
		int m_flCustomAutoExposureMax = 0;
		int m_flCustomBloomScale = 0;
		int m_flCustomBloomScaleMinimum = 0;
		int m_flBloomExponent = 0;
		int m_flBloomSaturation = 0;
		int m_flTonemapPercentTarget = 0;
		int m_flTonemapPercentBrightPixels = 0;
		int m_flTonemapMinAvgLum = 0;
		int m_flTonemapRate = 0;
	}DT_EnvTonemapController;

	struct
	{
		int m_flDuration = 0;
		int m_nType = 0;
	}DT_EnvScreenEffect;

	struct
	{
		int m_iszOverlayNames = 0;
		int m_flOverlayTimes = 0;
		int m_flStartTime = 0;
		int m_iDesiredOverlay = 0;
		int m_bIsActive = 0;
	}DT_EnvScreenOverlay;

	struct
	{
		int m_hTargetEntity = 0;
		int m_bState = 0;
		int m_bAlwaysUpdate = 0;
		int m_flLightFOV = 0;
		int m_bEnableShadows = 0;
		int m_bSimpleProjection = 0;
		int m_bLightOnlyTarget = 0;
		int m_bLightWorld = 0;
		int m_bCameraSpace = 0;
		int m_flBrightnessScale = 0;
		int m_LightColor = 0;
		int m_flColorTransitionTime = 0;
		int m_flAmbient = 0;
		int m_SpotlightTextureName = 0;
		int m_nSpotlightTextureFrame = 0;
		int m_flNearZ = 0;
		int m_flFarZ = 0;
		int m_nShadowQuality = 0;
		int m_flProjectionSize = 0;
		int m_flRotation = 0;
		int m_iStyle = 0;
	}DT_EnvProjectedTexture;

	struct
	{
		int m_flSequenceScale = 0;
	}DT_EnvParticleScript;

	struct
	{
		int m_fog_enable = 0;
		int m_fog_blend = 0;
		int m_fog_dirPrimary = 0;
		int m_fog_colorPrimary = 0;
		int m_fog_colorSecondary = 0;
		int m_fog_start = 0;
		int m_fog_end = 0;
		int m_fog_farz = 0;
		int m_fog_maxdensity = 0;
		int m_fog_colorPrimaryLerpTo = 0;
		int m_fog_colorSecondaryLerpTo = 0;
		int m_fog_startLerpTo = 0;
		int m_fog_endLerpTo = 0;
		int m_fog_maxdensityLerpTo = 0;
		int m_fog_lerptime = 0;
		int m_fog_duration = 0;
		int m_fog_HDRColorScale = 0;
		int m_fog_ZoomFogScale = 0;
	}DT_FogController;

	struct
	{
		int m_bDOFEnabled = 0;
		int m_flNearBlurDepth = 0;
		int m_flNearFocusDepth = 0;
		int m_flFarFocusDepth = 0;
		int m_flFarBlurDepth = 0;
		int m_flNearBlurRadius = 0;
		int m_flFarBlurRadius = 0;
	}DT_EnvDOFController;

	struct
	{
		int m_shadowDirection = 0;
		int m_envLightShadowDirection = 0;
		int m_bEnabled = 0;
		int m_bUseLightEnvAngles = 0;
		int m_LightColor = 0;
		int m_LightColorScale = 0;
		int m_flMaxShadowDist = 0;
	}DT_CascadeLight;

	struct
	{
		int m_vecColor = 0;
	}DT_EnvAmbientLight;

	struct
	{
		int m_iMaterialName = 0;
		int m_Info = 0;
		int m_hConstraintEntity = 0;
	}DT_EntityParticleTrail;

	struct
	{
		int m_vFreezingOrigin = 0;
		int m_flFrozenPerHitbox = 0;
		int m_flFrozen = 0;
		int m_bFinishFreezing = 0;
	}DT_EntityFreezing;

	struct
	{
		int m_hEntAttached = 0;
		int m_bCheapEffect = 0;
	}DT_EntityFlame;

	struct
	{
		int m_flStartTime = 0;
		int m_flFadeOutStart = 0;
		int m_flFadeOutLength = 0;
		int m_flFadeOutModelStart = 0;
		int m_flFadeOutModelLength = 0;
		int m_flFadeInStart = 0;
		int m_flFadeInLength = 0;
		int m_nDissolveType = 0;
		int m_vDissolverOrigin = 0;
		int m_nMagnitude = 0;
	}DT_EntityDissolve;

	struct
	{
		int m_Flags = 0;
		int m_LightStyle = 0;
		int m_Radius = 0;
		int m_Exponent = 0;
		int m_InnerAngle = 0;
		int m_OuterAngle = 0;
		int m_SpotRadius = 0;
	}DT_DynamicLight;

	struct
	{
		int m_bEnabled = 0;
		int m_MaxWeight = 0;
		int m_FadeDuration = 0;
		int m_Weight = 0;
		int m_lookupFilename = 0;
	}DT_ColorCorrectionVolume;

	struct
	{
		int m_vecOrigin = 0;
		int m_minFalloff = 0;
		int m_maxFalloff = 0;
		int m_flCurWeight = 0;
		int m_flMaxWeight = 0;
		int m_flFadeInDuration = 0;
		int m_flFadeOutDuration = 0;
		int m_netLookupFilename = 0;
		int m_bEnabled = 0;
		int m_bMaster = 0;
		int m_bClientSide = 0;
		int m_bExclusive = 0;
	}DT_ColorCorrection;

	struct
	{
		int m_qPreferredPlayerCarryAngles = 0;
		int m_bClientPhysics = 0;
	}DT_BreakableProp;

	struct
	{
		int m_nHaloIndex = 0;
		int m_bSpotlightOn = 0;
		int m_bHasDynamicLight = 0;
		int m_flSpotlightMaxLength = 0;
		int m_flSpotlightGoalWidth = 0;
		int m_flHDRColorScale = 0;
		int m_nRotationAxis = 0;
		int m_flRotationSpeed = 0;
	}DT_BeamSpotlight;

	struct
	{
		int m_usable = 0;
	}DT_BaseButton;

	struct
	{
		int m_vecFinalDest = 0;
		int m_movementType = 0;
		int m_flMoveTargetTime = 0;
	}DT_BaseToggle;

	struct
	{
		int localdata = 0;
		int pl = 0;
		int m_iFOV = 0;
		int m_iFOVStart = 0;
		int m_flFOVTime = 0;
		int m_iDefaultFOV = 0;
		int m_hZoomOwner = 0;
		int m_afPhysicsFlags = 0;
		int m_hVehicle = 0;
		int m_hUseEntity = 0;
		int m_hGroundEntity = 0;
		int m_iHealth = 0;
		int m_lifeState = 0;
		int m_iAmmo = 0;
		int m_iBonusProgress = 0;
		int m_iBonusChallenge = 0;
		int m_flMaxspeed = 0;
		int m_fFlags = 0;
		int m_iObserverMode = 0;
		int m_bActiveCameraMan = 0;
		int m_bCameraManXRay = 0;
		int m_bCameraManOverview = 0;
		int m_bCameraManScoreBoard = 0;
		int m_uCameraManGraphs = 0;
		int m_iDeathPostEffect = 0;
		int m_hObserverTarget = 0;
		int m_hViewModel = 0;
		int m_iCoachingTeam = 0;
		int m_szLastPlaceName = 0;
		int m_vecLadderNormal = 0;
		int m_ladderSurfaceProps = 0;
		int m_ubEFNoInterpParity = 0;
		int m_hPostProcessCtrl = 0;
		int m_hColorCorrectionCtrl = 0;
		int m_PlayerFog_m_hCtrl = 0;
		int m_vphysicsCollisionState = 0;
		int m_hViewEntity = 0;
		int m_bShouldDrawPlayerWhileUsingViewEntity = 0;
		int m_vecViewOffset = 0;
		int m_flDuckAmount = 0;
		int m_flDuckSpeed = 0;
		int m_nWaterLevel = 0;
	}DT_BasePlayer;

	struct
	{
		int m_flexWeight = 0;
		int m_blinktoggle = 0;
		int m_viewtarget = 0;
	}DT_BaseFlex;

	struct
	{
		int AnimTimeMustBeFirst = 0;
		int m_flSimulationTime = 0;
		int m_cellbits = 0;
		int m_cellX = 0;
		int m_cellY = 0;
		int m_cellZ = 0;
		int m_vecOrigin = 0;
		int m_angRotation = 0;
		int m_nModelIndex = 0;
		int m_fEffects = 0;
		int m_nRenderMode = 0;
		int m_nRenderFX = 0;
		int m_clrRender = 0;
		int m_iTeamNum = 0;
		int m_iPendingTeamNum = 0;
		int m_CollisionGroup = 0;
		int m_flElasticity = 0;
		int m_flShadowCastDistance = 0;
		int m_hOwnerEntity = 0;
		int m_hEffectEntity = 0;
		int moveparent = 0;
		int m_iParentAttachment = 0;
		int m_iName = 0;
		int movetype = 0;
		int movecollide = 0;
		int m_Collision = 0;
		int m_iTextureFrameIndex = 0;
		int m_bSimulatedEveryTick = 0;
		int m_bAnimatedEveryTick = 0;
		int m_bAlternateSorting = 0;
		int m_bSpotted = 0;
		int m_bSpottedBy = 0;
		int m_bSpottedByMask = 0;
		int m_bIsAutoaimTarget = 0;
		int m_fadeMinDist = 0;
		int m_fadeMaxDist = 0;
		int m_flFadeScale = 0;
		int m_nMinCPULevel = 0;
		int m_nMaxCPULevel = 0;
		int m_nMinGPULevel = 0;
		int m_nMaxGPULevel = 0;
		int m_flUseLookAtAngle = 0;
		int m_flLastMadeNoiseTime = 0;
		int m_flMaxFallVelocity = 0;
		int m_bEligibleForScreenHighlight = 0;
	}DT_BaseEntity;

	struct
	{
		int m_flWaveHeight = 0;
	}DT_BaseDoor;

	struct
	{
		int bcc_localdata = 0;
		int bcc_nonlocaldata = 0;
		int m_LastHitGroup = 0;
		int m_hActiveWeapon = 0;
		int m_flTimeOfLastInjury = 0;
		int m_nRelativeDirectionOfLastInjury = 0;
		int m_hMyWeapons = 0;
		int m_hMyWearables = 0;
	}DT_BaseCombatCharacter;

	struct
	{
		int overlay_vars = 0;
	}DT_BaseAnimatingOverlay;

	struct
	{
		int m_modelIndex = 0;
		int m_solidIndex = 0;
	}DT_BoneFollower;

	struct
	{
		int m_nSequence = 0;
		int m_nForceBone = 0;
		int m_vecForce = 0;
		int m_nSkin = 0;
		int m_nBody = 0;
		int m_nHitboxSet = 0;
		int m_flModelScale = 0;
		int m_flPoseParameter = 0;
		int m_flPlaybackRate = 0;
		int m_flEncodedController = 0;
		int m_bClientSideAnimation = 0;
		int m_bClientSideFrameReset = 0;
		int m_bClientSideRagdoll = 0;
		int m_nNewSequenceParity = 0;
		int m_nResetEventsParity = 0;
		int m_nMuzzleFlashParity = 0;
		int m_hLightingOrigin = 0;
		int serveranimdata = 0;
		int m_flFrozen = 0;
		int m_ScaleType = 0;
		int m_bSuppressAnimSounds = 0;
		int m_nHighlightColorR = 0;
		int m_nHighlightColorG = 0;
		int m_nHighlightColorB = 0;
	}DT_BaseAnimating;

	struct
	{
		int m_lifeState = 0;
		int m_bPerformAvoidance = 0;
		int m_bIsMoving = 0;
		int m_bFadeCorpse = 0;
		int m_iDeathPose = 0;
		int m_iDeathFrame = 0;
		int m_iSpeedModRadius = 0;
		int m_iSpeedModSpeed = 0;
		int m_bSpeedModActive = 0;
		int m_bImportanRagdoll = 0;
		int m_flTimePingEffect = 0;
	}DT_AI_BaseNPC;

	struct
	{
		int m_nBeamType = 0;
		int m_nBeamFlags = 0;
		int m_nNumBeamEnts = 0;
		int m_hAttachEntity = 0;
		int m_nAttachIndex = 0;
		int m_nHaloIndex = 0;
		int m_fHaloScale = 0;
		int m_fWidth = 0;
		int m_fEndWidth = 0;
		int m_fFadeLength = 0;
		int m_fAmplitude = 0;
		int m_fStartFrame = 0;
		int m_fSpeed = 0;
		int m_flFrameRate = 0;
		int m_flHDRColorScale = 0;
		int m_clrRender = 0;
		int m_nRenderFX = 0;
		int m_nRenderMode = 0;
		int m_flFrame = 0;
		int m_nClipStyle = 0;
		int m_vecEndPos = 0;
		int m_nModelIndex = 0;
		int m_vecOrigin = 0;
		int moveparent = 0;
	}DT_Beam;

	struct
	{
		int m_nModelIndex = 0;
		int m_hWeapon = 0;
		int m_nSkin = 0;
		int m_nBody = 0;
		int m_nSequence = 0;
		int m_nViewModelIndex = 0;
		int m_flPlaybackRate = 0;
		int m_fEffects = 0;
		int m_nAnimationParity = 0;
		int m_hOwner = 0;
		int m_nNewSequenceParity = 0;
		int m_nResetEventsParity = 0;
		int m_nMuzzleFlashParity = 0;
		int m_bShouldIgnoreOffsetAndAccuracy = 0;
	}DT_BaseViewModel;

	struct
	{
		int m_flDamage = 0;
		int m_DmgRadius = 0;
		int m_bIsLive = 0;
		int m_hThrower = 0;
		int m_vecVelocity = 0;
		int m_fFlags = 0;
	}DT_BaseGrenade;

	struct
	{
		int LocalWeaponData = 0;
		int LocalActiveWeaponData = 0;
		int m_iViewModelIndex = 0;
		int m_iWorldModelIndex = 0;
		int m_iWorldDroppedModelIndex = 0;
		int m_iState = 0;
		int m_hOwner = 0;
		int m_iClip1 = 0;
		int m_iClip2 = 0;
		int m_iPrimaryReserveAmmoCount = 0;
		int m_iSecondaryReserveAmmoCount = 0;
		int m_hWeaponWorldModel = 0;
		int m_iNumEmptyAttacks = 0;
	}DT_BaseCombatWeapon;

	struct
	{
		int m_nModelIndex = 0;
		int m_nBody = 0;
		int m_fEffects = 0;
		int moveparent = 0;
		int m_hCombatWeaponParent = 0;
	}DT_BaseWeaponWorldModel;



};

extern CNetvar * Netvar;