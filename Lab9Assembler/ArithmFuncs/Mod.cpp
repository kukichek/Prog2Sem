#include"Mod.h"

Mod::Mod() {
	operName = "getting remainder";
}

int Mod::operator() (int a, int b) {
	string error = "division by 0";
	if (!b) throw error;

	int result;
	__asm {
		mov eax, a
		cdq
		idiv b
		mov result, edx
	}
	return result;
}