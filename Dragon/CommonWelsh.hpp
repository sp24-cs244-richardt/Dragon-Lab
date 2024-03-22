#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Dragon.hpp"

using namespace std;

class CommonWelsh : public Dragon {
private:
	const string skinColor_ = "green";
	const string nativeRange_ = "Wales";
	int charisma_;
	int trustFactor_;
	int health_;
	int firePower_;
public:
	CommonWelsh();

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
	int GetTrust() {
		return trustFactor_;
	};

	void Train();
	void Print();
};