#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Dragon.hpp"
#include "CommonWelsh.hpp"

using namespace std;

CommonWelsh::CommonWelsh() {
	health_ = (rand() % 5) + 95;
	charisma_ = (rand() % 10) + 45;
	firePower_ = (rand() % 50) + 10;
	trustFactor_ = 5;
}

void CommonWelsh::Train() {
	firePower_ += trustFactor_;

	trustFactor_ = (trustFactor_ % 50) + 5;

	if (firePower_ > 100) {
		firePower_ = 100;
	}

	Dragon::Train();
}

int CommonWelsh::GetFirePower() {
	return firePower_;
};

int CommonWelsh::GetTrust() {
	return trustFactor_;
};

void CommonWelsh::Print()
{
	cout << "Common Welsh, skin color: green, native range: Wales, fire power: " << firePower_ << ", trush factor: " << trustFactor_ << endl;
}