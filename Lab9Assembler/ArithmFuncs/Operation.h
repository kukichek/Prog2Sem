#pragma once
#include<string>

using namespace std;

class Operation {
public:
	string operName;
	Operation() {}
	virtual int operator() (int a, int b) = 0;
};
