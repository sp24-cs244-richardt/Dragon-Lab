#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dragon {
private:
	string skinColor_;
	string nativeRange_;
	int firePower_;
public:
	virtual void Train() = 0;
	virtual void Print() = 0;
};