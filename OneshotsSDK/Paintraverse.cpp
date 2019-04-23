#include "Hooks.h"

PaintTraverseFn oPaintTraverse;
void __stdcall Hooks::PaintTraverse(unsigned int panel, bool forceRepaint, bool allowForce)
{
	oPaintTraverse(Interfaces->Panel, panel, forceRepaint, allowForce);

	{ // So we only render on 1 panel.
		static int drawPanel = 0;
		if (!drawPanel)
			if (!strcmp(Interfaces->Panel->GetName(panel), "MatSystemTopPanel"))
				drawPanel = panel;
			else
				return;
		if (drawPanel != panel)
			return;
	}
	
	/*how you draw stuff*/

	if (Config.esp)
	{
		CBaseEntity* local = (CBaseEntity*)Interfaces->ClientEntityList->GetClientEntity(Interfaces->EngineClient->GetLocalPlayer());

		for (size_t i = 1; i <= 64; i++)
		{
			CBaseEntity* entity = (CBaseEntity*)Interfaces->ClientEntityList->GetClientEntity(i);
			if (entity && entity->IsPlayer() && entity->GetHealth() && !entity->IsDormant() && i != Interfaces->EngineClient->GetLocalPlayer())
			{
				Vector feetpos, eyepos;
				if (Math.WorldToScreen(entity->GetEyePos() + Vector(0, 0, 10), eyepos) && Math.WorldToScreen(entity->GetOrigin(), feetpos))
				{
					int width = (feetpos.y - eyepos.y) / 2;
					int hight = (feetpos.y - eyepos.y);

					if (local && local->GetTeam() == entity->GetTeam())
						Interfaces->Surface->DrawSetColor(Color(0, 255, 0, 50));
					else
						Interfaces->Surface->DrawSetColor(Color(255, 0, 0, 50));

					Interfaces->Surface->DrawFilledRect(eyepos.x - width / 2, eyepos.y, eyepos.x + width / 2, eyepos.y + hight);
				}
			}
		}
	}
}