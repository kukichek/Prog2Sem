#pragma once
#include"Operation.h"

class Sub : public Operation {
public:
	Sub();
	int operator() (int a, int b);
};
