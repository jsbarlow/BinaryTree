//
// FILE: test.cpp
//

#include "game.h"
#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

int main()
{
	int done;
	Game game;
	done = 1;

	game.read();
	game.play();
	game.write();

	cout << "\nPress '0' when done." << endl;
	do
		cin >> done;
	while (done != 0);

	return 0;
}