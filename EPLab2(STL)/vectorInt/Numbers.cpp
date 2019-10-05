#include<fstream>
#include<iostream>
#include<numeric>
#include"fileLib.h"
#include"Numbers.h"

Numbers::Numbers() {}

void Numbers::push(int el) {
	_vec.push_back(el);
}

int Numbers::findMax() {
	string error = "Empty list";
	if (amount() == 0) throw error;
	return *max_element(_vec.begin(), _vec.end());
}

int Numbers::countEqual(int el) {
	return count(_vec.begin(), _vec.end(), el);
}

int Numbers::amount() {
	return _vec.size();
}

int Numbers::sum() {
	return accumulate(_vec.begin(), _vec.end(), 0);
}

double Numbers::average() {
	string error = "Dividing by 0";
	if (amount() == 0) throw error;
	return 1. * sum() / amount();
}