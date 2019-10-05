#pragma once
#include<iostream>

extern "C" void outDivisionBy0() {
	std::cout << "Division by 0\n";
}

extern "C" void outNum(int a) {
	std::cout << "x = " << a << "\n";
}