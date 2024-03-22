#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Dragon.hpp"

using namespace std;

class HungarianHorntail : public  Dragon {
private:
	const string skinColor_ = "black";
	const string nativeRange_ = "Hungary";
	int charisma_;
public:
	int health_;
	int firePower_;
	HungarianHorntail();

	int GetHealth() {
		return health_;
	};
	void SetHealth(int health) {
		health_ = health;
	};
	int GetFirePower() {
		return firePower_;
	};
	int GetCharisma() {
		return charisma_;
	};
	void SetCharisma(int charisma) {
		charisma_ = charisma;
	};
	void SetFirePower(int firePower) {
		firePower_ = firePower;
	};

	void Train();
	void Print();
};