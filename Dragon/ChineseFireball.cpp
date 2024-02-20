#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Dragon.hpp"
#include "ChineseFireball.hpp"

using namespace std;

ChineseFireBall::ChineseFireBall() {
	firePower_ = (rand() % 50) + 50;
}

void ChineseFireBall::Train() {
	firePower_ += (rand() % 15) + 10;

	if (firePower_ > 100) {
		firePower_ = 100;
	}
}

int ChineseFireBall::GetFirePower() {
	return firePower_;
};

void ChineseFireBall::Print()
{
	cout << "Chinese Fireball, skin color: scarlet, native range: China, fire power: " << firePower_ << endl;
}