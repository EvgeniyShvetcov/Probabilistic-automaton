#include "stdafx.h"
#include "State.h"
#include "Gambit.h"


State::State()
{
}


State::~State()
{
}

void EagleState::handle(double chance, Gambit* player)
{
	player->_eagleCount++;
	if (chance >= 0 && chance <= (1.0 / 6))
	{
		player->SetCurrentState(player->GetThreeState().get());
	}
	if (chance > (1.0 / 6) && chance <= (2.0 / 6))
	{
		player->SetCurrentState(player->GetFourState().get());
	}
	else if (chance > (2.0 / 6) && chance <= (5.0 / 6))
	{
		player->SetCurrentState(player->GetOtherState().get());
	}
	else if (chance > (5.0 / 6) && chance <= 1)
	{
		player->SetCurrentState(player->GetAbsorbState().get());
	}
}

void TailsState::handle(double chance, Gambit* player)
{
	player->_tailsCount++;
	if (chance >= 0 && chance <= (1.0 / 2))
	{
		player->SetCurrentState(player->GetEagleState().get());
	}
	else if (chance > (1.0 / 2) && chance <= 1)
	{
		player->SetCurrentState(player->GetTailsState().get());
	}
}

void ThreeState::handle(double chance, Gambit * player)
{
	player->_threeCount++;
	if (chance > 0 && chance <= (1.0 / 6))
	{
		player->SetCurrentState(player->GetFourState().get());
	}
	else if (chance > (1.0 / 6) && chance <= (4.0 / 6))
	{
		player->SetCurrentState(player->GetOtherState().get());
	}
	else if (chance > (4.0 / 6) && chance <= 1.0)
	{
		player->SetCurrentState(player->GetAbsorbState().get());
	}
}

void FourState::handle(double chance, Gambit * player)
{
	player->_fourCount++;
	if (chance > 0 && chance <= (1.0 / 6))
	{
		player->SetCurrentState(player->GetFourState().get());
	}
	else if (chance > (1.0 / 6) && chance <= (2.0 / 6))
	{
		player->SetCurrentState(player->GetThreeState().get());
	}
	else if (chance > (2.0 / 6) && chance <= (5.0 / 6))
	{
		player->SetCurrentState(player->GetOtherState().get());
	}
	else if (chance > (5.0 / 6) && chance <= 1.0)
	{
		player->SetCurrentState(player->GetAbsorbState().get());
	}
}

void OtherState::handle(double chance, Gambit* player)
{
	player->_otherCount++;
	if (chance >= 0 && chance <= (1.0 / 2))
	{
		player->SetCurrentState(player->GetEagleState().get());
	}
	else if (chance > (1.0 / 2) && chance <= 1)
	{
		player->SetCurrentState(player->GetTailsState().get());
	}
}

void AbsorbState::handle(double chance, Gambit * player)
{
	player->EndGame();
}


