#include <iostream>
#include <string>
#include <locale>
#include <random>
#include <time.h>
#include <list>
#include "Dragon.hpp";
#include "ChineseFireball.hpp"
#include "CommonWelsh.hpp"
#include "HungarianHorntail.hpp"

enum GameState {
	Menu,
	Training,
	Recruiting,
	Battling
};

GameState currentState = Menu;
list<Dragon*> playerDragons = list<Dragon*>(0);

bool quitting = false;

void TrainDragon(Dragon* dragon) {
	dragon->Train();
}

string StringToLower(string text) {
	string loweredString = "";

	for (auto elem : text) {
		loweredString += tolower(elem);
	}
		
	return loweredString;
}

void DoTraining() {

}

void DoRecruiting() {

}

void DoBattling() {

}

void DoQuitting() {
	bool recognized = false;
	string selection;

	while (!recognized) {
		cout << "Are you sure you'd like to quit?" << endl;
		cout << "0: Yes" << endl << "1: No" << endl;
		cin >> selection;

		if (selection == "0" || StringToLower(selection) == "yes" || StringToLower(selection) == "y")
		{
			recognized = true;
			quitting = true;
		}
		else if (selection == "1" || StringToLower(selection) == "no" || StringToLower(selection) == "n")
		{
			recognized = true;
		}
		else {
			cout << "\"" << selection << "\" is not a recognized option" << endl;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	// generate dragons
	for (int i = 0; i < 3; i++) {
		int randDragon = rand() % 3;

		switch (randDragon) {
		case 0:
			playerDragons.push_back(new ChineseFireBall());
			break;

		case 1:
			playerDragons.push_back(new CommonWelsh());
			break;

		case 2:
			playerDragons.push_back(new HungarianHorntail());
			break;

		default: // This should never happen
			playerDragons.push_back(new ChineseFireBall());
			break;
		}
	}

	string selection;

	while (!quitting) {
		cout << "What would you like to do?" << endl;
		cout << "0: Train" << endl << "1: Recruit" << endl << "2: Battle" << endl << "3: Quit" << endl;
		cin >> selection;

		if (selection == "0" || StringToLower(selection) == "train")
		{
			cout << endl;
			DoTraining();
		}
		else if (selection == "1" || StringToLower(selection) == "recruit")
		{
			cout << endl;
			DoRecruiting();
		}
		else if (selection == "2" || StringToLower(selection) == "battle")
		{
			cout << endl;
			DoBattling();
		}
		else if (selection == "3" || StringToLower(selection) == "quit")
		{
			cout << endl;
			DoQuitting();
		}
		else {
			cout << "\"" << selection << "\" is not a recognized option" << endl;
		}

		cout << endl;
	}


}