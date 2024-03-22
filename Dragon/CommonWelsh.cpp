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

	health_ -= 20;
}

void CommonWelsh::Print()
{
	cout << "Common Welsh,\tskin color: green,\tnative range: Wales,\thealth: " << health_ << "\tfire power: " << firePower_ << ",\ttrush factor: " << trustFactor_ << endl;
}