#pragma once
#include<iostream>

extern "C" void outEmptySet() {
	std::cout << "Equation has no decision\n";
}

extern "C" void outR() {
	std::cout << "The solution is a set of real numbers\n";
}

extern "C" void outNum(float a) {
	std::cout << a << " is a solution of an equation\n";
}