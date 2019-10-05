#include"Operation.h"

int Operation::operator() (int a) {
	int result;
	__asm {
		mov eax, a
		imul a
		inc eax
		imul a
		imul a
		inc eax
		imul a
		mov result, eax
	}
}