#include<iostream>
#include"outFuncs.h"

using namespace std;

extern "C" void __fastcall OutDecision(short int, short int);

int main() {
	short int a, b;
	cout << "Enter, please, two numbers:\n";
	cin >> a >> b;
	OutDecision(a, b);

	system("pause");

	return 0;
}