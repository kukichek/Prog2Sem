#pragma once
#include<vector>
#include<utility>
#include<iostream>
#include"OperationList.h"
#include"Operation.h"

class Processor {
	int operI, a, b;
	OperationList opList;

	void setOperIndex();
	void setOperands();
public:
	Processor();
	void operator() ();
	~Processor();
};