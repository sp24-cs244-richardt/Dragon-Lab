#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dragon {
private:
	string skinColor_;
	string nativeRange_;
	int health_;
	int charisma_;
	int firePower_;
public:
	void Train();
	virtual void Print() = 0;
};