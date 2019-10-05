#include"Sub.h"

Sub::Sub() {
	operName = "substraction";
}

int Sub::operator() (int a, int b) {
	int result;
	__asm {
		mov eax, a
		sub eax, b
		mov result, eax
	}
	return result;
}