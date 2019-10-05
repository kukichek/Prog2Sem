#pragma once
#include<iostream>
#include<windows.h>

using namespace std;

extern "C" void __stdcall WordSwap(WORD&, WORD&);

class Proc {
	WORD a, b;
public:
	Proc() {
		cout << "Enter, please, two numbers of type WORD:\n";
		cin >> a >> b;
	}
	void operator() () {
		WordSwap(a, b);
		cout << "Numbers a and b after swapping are:\n";
		cout << "a = " << a << ", b = " << b << ";\n";
	}
};