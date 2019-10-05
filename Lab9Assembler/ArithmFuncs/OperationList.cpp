#include"OperationList.h"

OperationList::OperationList() {
	list.push_back(new Sub);
	list.push_back(new Mult);
	list.push_back(new Div);
	list.push_back(new Mod);
}

Operation* OperationList::operator[] (int index) {
	return list[index];
}

OperationList::~OperationList() {
	list.~vector();
}