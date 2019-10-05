#include"FibonacciNums.h"

int FibonacciNums::operator()() {
	int amountOfFNumsInInt;

	_asm {
		mov esi, 2
		mov ecx, 1
		mov ebx, 1

beginLoop:	mov eax, ebx
			add eax, ecx

			jc endLoop

			inc esi

			mov ecx, ebx
			mov ebx, eax

			jmp beginLoop

endLoop:	mov amountOfFNumsInInt, esi
	}

	return amountOfFNumsInInt;
}