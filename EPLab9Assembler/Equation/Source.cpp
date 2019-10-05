/*
2.	Решить уравнение ax+b=0 (исследуйте 3 возможных варианта решения)
*/

#include<iostream>
#include"outFuncs.h"

using namespace std;

extern "C" void OutDecision(int, int);

int main() {
	int a, b;
	cout << "Enter, please, coefficients of an equation ax + b:\n";
	cin >> a >> b;
	OutDecision(a, b);

	system("pause");

	return 0;
}