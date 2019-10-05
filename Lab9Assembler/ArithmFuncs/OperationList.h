#pragma once
#include<vector>
#include"Sub.h"
#include"Mult.h"
#include"Div.h"
#include"Mod.h"

struct OperationList {
	vector<Operation*> list;
	OperationList();
	Operation* operator[] (int index);
	~OperationList();
};
