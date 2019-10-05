#pragma once
#include"Operation.h"

class Mod : public Operation {
public:
	Mod();
	int operator() (int a, int b);
};
