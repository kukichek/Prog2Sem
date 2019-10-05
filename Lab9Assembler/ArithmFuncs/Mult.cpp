#include"Mult.h"

Mult::Mult() {
	operName = "multiplication";
}

int Mult::operator() (int a, int b) {
	int result;
	__asm {
		mov eax, a
		imul b
		mov result, eax
	}
	return result;
}