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
	if (chance >= 0 && chance <= (double)(1.0 / 3))
	{
		player->SetCurrentState(*player->GetTFState());
		player->_tfCount++;
	}
	else if (chance > (1.0 / 3) && chance <= (5.0 / 6))
	{
		player->SetCurrentState(*player->GetOtherState());
		player->_otherCount++;
	}
	else if (chance > (5.0 / 6) && chance <= 1)
	{
		player->SetCurrentState(*player->GetAbsorbState());
	}
}

void TailsState::handle(double chance, Gambit* player)
{
	if (chance >= 0 && chance <= (1.0 / 2))
	{
		player->SetCurrentState(*player->GetEagleState());
		player->_eagleCount++;
	}
	else if (chance > (1.0 / 2) && chance <= 1)
	{
		player->SetCurrentState(*player->GetTailsState());
		player->_tailsCount++;
	}
}

void TFState::handle(double chance, Gambit* player)
{
	if (chance >= 0 && chance <= (1.0 / 3))
	{
		player->SetCurrentState(*player->GetTFState());
		player->_tfCount++;
	}
	else if (chance > (1.0 / 3) && chance <= (5.0 / 6))
	{
		player->SetCurrentState(*player->GetOtherState());
		player->_otherCount++;
	}
	else if (chance > (5.0 / 6) && chance <= 1)
	{
		player->SetCurrentState(*player->GetAbsorbState());
	}
}

void OtherState::handle(double chance, Gambit* player)
{
	if (chance >= 0 && chance <= (1.0 / 2))
	{
		player->SetCurrentState(*player->GetEagleState());
		player->_eagleCount++;
	}
	else if (chance > (1.0 / 2) && chance <= 1)
	{
		player->SetCurrentState(*player->GetTailsState());
		player->_tailsCount++;
	}
}

void AbsorbState::handle(double chance, Gambit * player)
{
	player->EndGame();
}
