#pragma once

class Gambit;

class State
{
public:
	State();
	virtual ~State();

	virtual void handle(double chance, Gambit* player) = 0;
};

class EagleState : public State
{
public:
	void handle(double chance, Gambit* player) override;
};

class TailsState : public State
{
public:
	void handle(double chance, Gambit* player) override;
};

class TFState : public State
{
public:
	void handle(double chance, Gambit* player) override;
};

class OtherState : public State
{
public:
	void handle(double chance, Gambit* player) override;
};

class AbsorbState : public State
{
public:
	void handle(double chance, Gambit* player) override;
};