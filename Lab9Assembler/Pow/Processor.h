#pragma once
#include<iostream>
#include"Operation.h"

class Processor {
	int a;
public:
	Processor();
	int getOperand();
	void operator() ();
};