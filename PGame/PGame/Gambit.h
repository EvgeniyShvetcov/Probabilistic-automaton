#pragma once
#include "State.h"
#include <memory>

class Gambit
{
private:
	std::shared_ptr<EagleState*> _eagleState;
	std::shared_ptr<TailsState*> _tailsState;
	std::shared_ptr<TFState*> _tfState;
	std::shared_ptr<OtherState*> _otherState;

	std::shared_ptr<AbsorbState*> _absorbState;

	State* _currentState;

	bool _isActive;

public:
	Gambit();
	Gambit(State* state);
	virtual ~Gambit();

	void PlayGame(long& gameCount);
	void EndGame();

	State* GetCurrentState();
	void SetCurrentState(State* state);

	const std::shared_ptr<EagleState*>& GetEagleState();
	const std::shared_ptr<TailsState*>& GetTailsState();
	const std::shared_ptr<TFState*>& GetTFState();
	const std::shared_ptr<OtherState*>& GetOtherState();

	const std::shared_ptr<AbsorbState*>& GetAbsorbState();

	long _eagleCount;
	long _tailsCount;
	long _tfCount;
	long _otherCount;

};

