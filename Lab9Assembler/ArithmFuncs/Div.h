#pragma once
#include"Operation.h"

class Div : public Operation {
public:
	Div();
	int operator() (int a, int b);
};
