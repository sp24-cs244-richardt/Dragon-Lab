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
	int health_;
	int charisma_;
	int firePower_;
public:
	ChineseFireBall();
	int GetFirePower();
	void Train();
	void Print();
};