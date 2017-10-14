#include "stdafx.h"
#include "Gambit.h"
#include <random>


Gambit::Gambit() : _isActive(false)
{
	_eagleCount = 0;
	_tailsCount = 0;
	_otherCount = 0;
	_tfCount = 0;
	_eagleState = std::make_shared<EagleState*>(new EagleState());
	_tailsState = std::make_shared<TailsState*>(new TailsState());
	_tfState = std::make_shared<TFState*>(new TFState());
	_otherState = std::make_shared<OtherState*>(new OtherState());
	_absorbState = std::make_shared<AbsorbState*>(new AbsorbState());
	_currentState = *_tailsState;
}

Gambit::Gambit(State * state)
{
	_currentState = state;
}


Gambit::~Gambit()
{
}

void Gambit::PlayGame(long& gameCount)
{
	double chance = 0;
	std::random_device rd;
	std::default_random_engine re(rd());
	std::uniform_real_distribution<double> unif(0, 1);
	long i = 0;
	_isActive = true;
	while(_isActive && (i < gameCount))
	{
		chance = unif(re);
		_currentState->handle(chance, this);
		++i;
	}
	gameCount = i - 1;
}

void Gambit::EndGame()
{
	_isActive = false;
}

State * Gambit::GetCurrentState()
{
	return nullptr;
}

void Gambit::SetCurrentState(State * state)
{
	_currentState = state;
}

const std::shared_ptr<EagleState*>& Gambit::GetEagleState()
{
	return _eagleState;
}

const std::shared_ptr<TailsState*>& Gambit::GetTailsState()
{
	return _tailsState;
}

const std::shared_ptr<TFState*>& Gambit::GetTFState()
{
	return _tfState;
}


const std::shared_ptr<OtherState*>& Gambit::GetOtherState()
{
	return _otherState;
}

const std::shared_ptr<AbsorbState*>& Gambit::GetAbsorbState()
{
	return _absorbState;
}
