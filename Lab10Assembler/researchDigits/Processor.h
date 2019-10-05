#pragma once
#include<iostream>
#include"DigitCounter.h"

using namespace std;

class Processor {
	int num;
public:
	Processor();
	void operator() ();
};