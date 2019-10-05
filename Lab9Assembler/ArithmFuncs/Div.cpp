#include"Div.h"

Div::Div() {
	operName = "getting incomplete quotient";
}

int Div::operator() (int a, int b) {
	string error = "division by 0";
	if (!b) throw error;

	int result;
	__asm {
		mov eax, a
		cdq
		idiv b
		mov result, eax
	}
	return result;
}