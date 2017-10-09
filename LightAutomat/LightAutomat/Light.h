#pragma once
#include <memory>

class State;
class GreenLightState;
class RedLightState;

class Light
{
private:
	std::shared_ptr< GreenLightState* > _greenLightState;
	std::shared_ptr< RedLightState* > _redLightState;

	State*  _currentState;
	std::vector<int> _stateData;
public:
	Light();
	Light(State* state);
	~Light();

	void SetCurrentState(State * State);

	std::shared_ptr< GreenLightState* >& GetGreenState();
	std::shared_ptr< RedLightState * >& GetRedState();

	void LightEvent(int Input, double Chance);

	long GetOpenCountState();
	long GetCloseCountState();

	void AddStateData(int StateNumber);

	void SaveData(std::string Path);
};

