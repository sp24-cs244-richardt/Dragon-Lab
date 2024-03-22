#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Dragon.hpp"
#include "ChineseFireball.hpp"

using namespace std;

ChineseFireBall::ChineseFireBall() {
	health_ = (rand() % 35) + 50;
	charisma_ = (rand() % 30) + 25;
	firePower_ = (rand() % 50) + 50;
}

void ChineseFireBall::Train() {
	firePower_ += (rand() % 15) + 10;

	if (firePower_ > 100) {
		firePower_ = 100;
	}

	health_ -= 20;
}

void ChineseFireBall::Print()
{
	cout << "Chinese Fireball,\tskin color: scarlet,\tnative range: China,\thealth: " << health_ << "\tfire power : " << firePower_ << endl;
}