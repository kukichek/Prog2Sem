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
	int getSize() {
		int size;
		in >> size;
		return size;
	}
	void operator() (int size, int **arr) {
		int a;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				in >> a;
				arr[i][j] = a;
			}
		}
	}
};