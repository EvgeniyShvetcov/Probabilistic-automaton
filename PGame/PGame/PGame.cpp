// PGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Gambit.h"
#include "State.h"

using namespace std;

int main()
{
	Gambit* gambit = new Gambit();
	long countOfGame = 10000;
	gambit->PlayGame(countOfGame);
	cout << "Eagle state count: " << ((double)gambit->_eagleCount * 100.0 / (double)countOfGame)  << endl;
	cout << "Tails state count: " << ((double)gambit->_tailsCount * 100.0 / (double)countOfGame) << endl;
	cout << "TF state count: " << ((double)gambit->_tfCount * 100.0 / (double)countOfGame) << endl;
	cout << "Other state count: " << ((double)gambit->_otherCount * 100.0 / (double)countOfGame) << endl;
    return 0;
}

