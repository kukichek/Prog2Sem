#pragma once
#include<fstream>
#include<string>
#include<cctype>
#include"fileLib.h"

using namespace std;

class Processor {
	ifstream in;
public:
	Processor(string nameOfFile) {
		in.open(nameOfFile);
		string err;
		if (!isValidFile(in, err)) throw err;
	}
	
	int* operator() () {
		string num;
		in >> num;

		int* ans = new int[num.length() + 1];
		ans[0] = num.length();
		string::reverse_iterator begin = num.rbegin();
		string::reverse_iterator end = num.rend();

		for (auto i = begin; i != end; ++i) {
			if (isdigit(*i)) {
				ans[i - begin + 1] = *i - '0';
			} else {
				throw (string)("String isn't a positive number");
			}
		}
		return ans;
	}
};