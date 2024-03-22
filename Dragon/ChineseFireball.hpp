#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Dragon.hpp"

using namespace std;

class ChineseFireBall : public Dragon {
private:
	const string skinColor_ = "scarlet";
	const string nativeRange_ = "China";
	int charisma_;
public:
	int health_;
	int firePower_;
	ChineseFireBall();

	int GetHealth() {
		return health_;
	};
	void SetHealth(int health) {
		health_ = health;
	};
	int GetFirePower() {
		return firePower_;
	};
	void SetFirePower(int firePower) {
		firePower_ = firePower;
	};
	int GetCharisma() {
		return charisma_;
	};
	void SetCharisma(int charisma) {
		charisma_ = charisma;
	};

	void Train();
	void Print();
};