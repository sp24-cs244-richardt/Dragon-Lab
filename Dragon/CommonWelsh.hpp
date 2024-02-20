#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Dragon.hpp"

using namespace std;

class CommonWelsh : public Dragon {
private:
	const string skinColor_ = "green";
	const string nativeRange_ = "Wales";
	int firePower_;
	int trustFactor_;
public:
	CommonWelsh();
	int GetFirePower();
	int GetTrust();
	void Train();
	void Print();
};