// PGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Gambit.h"
#include "State.h"

#ifdef _DEBUG
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#endif

using namespace std;

int main()
{
	{
		Gambit* gambit = new Gambit();
		long countOfGame = 10000;
		gambit->PlayGame(countOfGame);
		cout << "Eagle state count: " << ((double)gambit->_eagleCount * 100.0 / (double)countOfGame) << endl;
		cout << "Tails state count: " << ((double)gambit->_tailsCount * 100.0 / (double)countOfGame) << endl;
		cout << "Three state count: " << ((double)gambit->_threeCount * 100.0 / (double)countOfGame) << endl;
		cout << "Four state count: " << ((double)gambit->_fourCount * 100.0 / (double)countOfGame) << endl;
		cout << "Other state count: " << ((double)gambit->_otherCount * 100.0 / (double)countOfGame) << endl;
		cout << "Absorb state count: " << ((double)1.0 * 100.0 / (double)countOfGame) << endl;
		delete gambit;
	}
	_CrtDumpMemoryLeaks();
	return 0;

}

