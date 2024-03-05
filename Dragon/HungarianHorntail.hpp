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
	int health_;
	int charisma_;
	int firePower_;
public:
	HungarianHorntail();
	int GetFirePower();
	void Train();
	void Print();
};