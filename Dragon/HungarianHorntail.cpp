#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Dragon.hpp"
#include "HungarianHorntail.hpp"

using namespace std;

HungarianHorntail::HungarianHorntail() {
	health_ = (rand() % 30) + 60;
	charisma_ = (rand() % 20) + 75;
	firePower_ = (rand() % 75) + 50;
}


void HungarianHorntail::Train() {
	if (firePower_ < 20) {
		firePower_ += 5;
	}
	else {
		firePower_ += (rand() % 25) + 15;
	}

	if (firePower_ > 100) {
		firePower_ = 100;
	}

	health_ -= 20;
}

void HungarianHorntail::Print()
{
	cout << "Hungarian Horntail,\tskin color: black,\tnative range: Hungary,\thealth: " << health_ << "\tfire power: " << firePower_ << endl;
}