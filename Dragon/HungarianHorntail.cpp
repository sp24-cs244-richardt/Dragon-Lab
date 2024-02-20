#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Dragon.hpp"
#include "HungarianHorntail.hpp"

using namespace std;

HungarianHorntail::HungarianHorntail() {
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
}

int HungarianHorntail::GetFirePower() {
	return firePower_;
};

void HungarianHorntail::Print()
{
	cout << "Hungarian Horntail, skin color: black, native range: Hungary, fire power: " << firePower_ << endl;
}