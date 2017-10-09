#include "stdafx.h"
#include "State.h"
#include "Light.h"

void GreenLightState::Handle(int Input, double Chance, Light* light)
{
	if (Input == 0 && Chance <= 1)
	{
		light->SetCurrentState(*light->GetGreenState());
		light->AddStateData(0);
	}
	if (Input == 1 && (Chance > 0.2 && Chance <= 1))
	{
		light->SetCurrentState(*light->GetGreenState());
		light->AddStateData(0);
	}
	else if (Input == 1 && Chance <=0.2)
	{
		light->SetCurrentState(*light->GetRedState());
		light->AddStateData(1);
	}
}

void RedLightState::Handle(int Input, double Chance, Light* light)
{
	if (Input == 1 && Chance <= 0.5)
	{
		light->SetCurrentState(*light->GetGreenState());
		light->AddStateData(0);
	}
	else if (Input == 1 && (Chance >0.5 && Chance <= 1))
	{
		light->SetCurrentState(*light->GetRedState());
		light->AddStateData(1);
	}
	if (Input == 0 && Chance <= 1)
	{
		light->SetCurrentState(*light->GetGreenState());
		light->AddStateData(0);
	}
}
