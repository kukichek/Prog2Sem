#pragma once
#include"Operation.h"

class Mult : public Operation {
public:
	Mult();
	int operator() (int a, int b);
};
