#include "stdafx.h"
#include "Light.h"
#include "State.h"
#include <algorithm>
#include <fstream>

Light::Light()
{
	_greenLightState = std::make_shared< GreenLightState* >(new GreenLightState());
	_redLightState = std::make_shared < RedLightState* >(new RedLightState());
	_currentState = *_greenLightState;
}

Light::~Light()
{
}

void Light::SetCurrentState(State * State)
{
	_currentState = State;
}

std::shared_ptr<GreenLightState*>& Light::GetGreenState()
{
	return _greenLightState;
}

std::shared_ptr<RedLightState*>& Light::GetRedState()
{
	return _redLightState;
}

void Light::LightEvent(int Input, double Chance)
{
	_currentState->Handle(Input, Chance, this);
}

long Light::GetOpenCountState()
{
	long opencount = 0;
	if (_stateData.size() != 0)
	{
		std::for_each(_stateData.cbegin(), _stateData.cend(), [&opencount](const auto& item)
		{
			if (item == 0)
			{
				++opencount;
			}
		});
	}
	return opencount;
}

long Light::GetCloseCountState()
{
	long closecount = 0;
	if (_stateData.size() != 0)
	{
		std::for_each(_stateData.cbegin(), _stateData.cend(), [&closecount](const auto& item)
		{
			if (item == 0)
			{
				++closecount;
			}
		});
	}
	return closecount;
}

void Light::AddStateData(int StateNumber)
{
	_stateData.push_back(StateNumber);
}

void Light::SaveData(std::string Path)
{
	std::ofstream out("file.txt");
	for (auto i = 0; i < _stateData.size(); i++)
	{
		out << i << ": " << _stateData[i] << "\n";
	}
}
