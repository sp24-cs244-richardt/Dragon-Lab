#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dragon {
private:
	string skinColor_;
	string nativeRange_;
	int charisma_;
	int health_;
	int firePower_;
public:
	virtual void Train() = 0;
	virtual void Print() = 0;
	virtual int GetHealth() = 0;
	virtual void SetHealth(int health) = 0;
	virtual int GetFirePower() = 0;
	virtual void SetFirePower(int firePower) = 0;
	virtual int GetCharisma() = 0;
	virtual void SetCharisma(int charisma) = 0;
};