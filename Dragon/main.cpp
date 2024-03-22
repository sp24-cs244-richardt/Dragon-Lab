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
int dragonCount = 0;

Dragon* GetDragon(int pos) {
	int temp = 0;

	for (const auto& dragon : playerDragons)
	{
		if (pos == temp) {
			return dragon;
		}
		temp++;
	}

	return nullptr;
}

void AddDragonBack(Dragon* dragon) {
	playerDragons.push_back(dragon);
	dragonCount++;
}

void AddDragonFront(Dragon* dragon) {
	playerDragons.push_front(dragon);
	dragonCount++;
}

void RemoveDragon(Dragon* dragon) {
	playerDragons.remove(dragon);
	dragonCount--;
}

bool quitting = false;

void TrainDragon(Dragon* dragon) {
	dragon->Train();
}

Dragon* RandomDragon() {
	int randDragon = rand() % 3;

	switch (randDragon) {
	case 0:
		return new ChineseFireBall();
		break;

	case 1:
		return new CommonWelsh();
		break;

	case 2:
		return new HungarianHorntail();
		break;

	default: // This should never happen
		return new ChineseFireBall();
		break;
	}
}

string StringToLower(string text) {
	string loweredString = "";

	for (auto elem : text) {
		loweredString += tolower(elem);
	}
		
	return loweredString;
}

void DoBattling(Dragon* fightingDragon, bool yourTurn = true, Dragon* wildDragon = RandomDragon()) {
	cout << "you are fighting: " << endl;
	wildDragon->Print();

	int wildOriginalHealth = wildDragon->GetHealth();
	int fightingOriginalHealth = fightingDragon->GetHealth();

	while (fightingDragon->GetHealth() > 0 && wildDragon->GetHealth() > 0) {
		double hit = (rand() % 101);

		if (yourTurn) {
			int hitPower = fightingDragon->GetFirePower() * (hit / 100.0);
			wildDragon->SetHealth(wildDragon->GetHealth() - hitPower);

			if (hit == 0) {
				cout << "Your dragon completely missed!" << endl;
			}
			else if (hit == 100) {
				cout << "Your dragon did a direct hit!" << endl;
			}
			else {
				cout << "Your dragon was hit for " << hitPower << " health!" << endl;
			}

			cout << "The wild dragon has " << wildDragon->GetHealth() << " remaining" << endl;
		}
		else {
			int hitPower = wildDragon->GetFirePower() * (hit / 100.0);
			fightingDragon->SetHealth(fightingDragon->GetHealth() - hitPower);
			
			if (hit == 0) {
				cout << "The wild dragon completely missed!" << endl;
			}
			else if (hit == 100) {
				cout << "The wild dragon did a direct hit!" << endl;
			}
			else {
				cout << "You were hit for " << hitPower << " health!" << endl;
			}

			cout << "Your dragon has " << fightingDragon->GetHealth() << " remaining" << endl;
		}

		yourTurn = !yourTurn;
	}

	if (fightingDragon->GetHealth() <= 0) {
		cout << "Your dragon is dead! XD" << endl;
		RemoveDragon(fightingDragon);
	}

	if (wildDragon->GetHealth() <= 0) {
		cout << "The wild dragon is dead!" << endl;
		wildDragon->SetHealth(wildOriginalHealth);
		AddDragonBack(wildDragon);

		fightingDragon->SetHealth(fightingOriginalHealth + 10);
		RemoveDragon(fightingDragon);
		AddDragonFront(fightingDragon);
	}
}

void DoTraining() {
	string selection;
	bool recognized = false;

	cout << "What dragon would you like to train?" << endl;
	for (int i = 0; i < dragonCount; i++) {
		cout << i << ": ";
		GetDragon(i)->Print();
	}
	
	int dragonToTrain = -1;
	while (dragonToTrain == -1) {
		cin >> selection;

		int dragonSelection = -1;

		try {
			dragonSelection = stoi(selection);
		}
		catch (const std::exception& e) {
			cout << "Dragon " << selection << " does not exist" << endl;
			continue;
		}

		if (dragonSelection >= 0 && dragonSelection < playerDragons.size()) {
			dragonToTrain = dragonSelection;
		}
		else {
			cout << "Dragon " << selection << " does not exist" << endl;
		}
	}

	Dragon* trainingDragon = GetDragon(dragonToTrain);
	trainingDragon->Train();
	RemoveDragon(trainingDragon);
	AddDragonBack(trainingDragon);
	
	if ((rand() % 100) < 10) {
		cout << "A wild dragon appeared and wants to fight!" << endl;
		DoBattling(trainingDragon, false);
	}
}

void DoRecruiting() {
	string selection;
	bool recognized = false;

	cout << "What dragon would you like to recruit with?" << endl;
	for (int i = 0; i < dragonCount; i++) {
		cout << i << ": ";
		GetDragon(i)->Print();
	}

	int dragonToRecruit = -1;
	while (dragonToRecruit == -1) {
		cin >> selection;

		int dragonSelection = -1;

		try {
			dragonSelection = stoi(selection);
		}
		catch (const std::exception& e) {
			cout << "Dragon " << selection << " does not exist" << endl;
			continue;
		}

		if (dragonSelection >= 0 && dragonSelection < playerDragons.size()) {
			dragonToRecruit = dragonSelection;
		}
		else {
			cout << "Dragon " << selection << " does not exist" << endl;
		}
	}

	Dragon* recruitingDragon = GetDragon(dragonToRecruit);

	Dragon* wildDragon = RandomDragon();
	cout << "you are recruiting: " << endl;
	wildDragon->Print();

	if (wildDragon->GetCharisma() < recruitingDragon->GetCharisma()) {
		cout << "Recruitment was successful!" << endl;
		AddDragonBack(wildDragon);
		recruitingDragon->SetCharisma(recruitingDragon->GetCharisma() + 5);

		if (recruitingDragon->GetCharisma() > 100) {
			recruitingDragon->SetCharisma(100);
		}
	}
	else {
		cout << "Recruitment failed!" << endl;
		DoBattling(recruitingDragon, false, wildDragon);
	}
}

void PickDragonToFight() {
	string selection;
	bool recognized = false;

	cout << "What dragon would you like to have fight?" << endl;
	for (int i = 0; i < dragonCount; i++) {
		cout << i << ": ";
		GetDragon(i)->Print();
	}

	int dragonToFight = -1;
	while (dragonToFight == -1) {
		cin >> selection;

		int dragonSelection = -1;

		try {
			dragonSelection = stoi(selection);
		}
		catch (const std::exception& e) {
			cout << "Dragon " << selection << " does not exist" << endl;
			continue;
		}

		if (dragonSelection >= 0 && dragonSelection < playerDragons.size()) {
			dragonToFight = dragonSelection;
		}
		else {
			cout << "Dragon " << selection << " does not exist" << endl;
		}
	}

	DoBattling(GetDragon(dragonToFight));
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
		AddDragonBack(RandomDragon());
	}

	string selection;

	while (!quitting) {
		if (dragonCount <= 0) {
			cout << "RNG ruined your day and all of your dragons are dead!" << endl;
			cout << "Thanks for playing!" << endl;
			quitting = true;
			continue;
		}

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
			PickDragonToFight();
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