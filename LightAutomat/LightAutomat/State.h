#pragma once

class Light;

class State
{
public:
	virtual void Handle(int Input, double Chance, Light* light) = 0;
};

class GreenLightState : public State
{
public:
	void Handle(int Input, double Chance, Light* light) override;
};

class RedLightState : public State
{
public:
	void Handle(int Input, double Chance, Light* light) override;
};
