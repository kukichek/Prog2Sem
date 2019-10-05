#pragma once
#include<fstream>
#include<string>
#include"fileLib.h"

class GetArray {
	std::ifstream in;
public:
	GetArray(std::string fileName) {
		std::string error;
		in.open(fileName);
		if (!isValidFile(in, error)) {
			throw error;
		}
	}
	int operator() (int *arr) {
		int a;
		int len = 0;
		while (in >> a) {
			arr[len] = a;
			len++;
		}
		return len;
	}
};