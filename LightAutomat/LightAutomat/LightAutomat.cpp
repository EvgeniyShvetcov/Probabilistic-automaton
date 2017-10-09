// LightAutomat.cpp: оределяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <random>
#include "Light.h"
#include "State.h"
#include <ctime>

using namespace std;

int main()
{
	Light* light = new Light();
	double p = 0;
	srand(time(0));
	uniform_real_distribution<double> unif(0, 1);
	default_random_engine re;

	for (auto i = 0; i < 100000; i++)
	{
		p = unif(re);
		light->LightEvent(rand() % 2, p);
	}
	auto count = light->GetOpenCountState();
	return 0;
}

