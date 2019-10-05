#include"NumResearch.h"

bool NumResearch::isSymmetric(int n) {
	int numeral[10];
	int result = 0;

	_asm {
		mov eax, n

		cmp eax, 0
		jg gr
		neg eax

		gr :

		mov esi, 0
		mov ebx, 10		// делитель

		loopBegin1:
		cmp eax, 0
			jna loopEnd1
			cdq
			div ebx
			mov numeral[4 * esi], edx
			inc esi
			jmp loopBegin1
			loopEnd1 :

		dec esi
			mov ecx, 0

		cmp n, 0
		je loopEnd2

			loopBegin2 :
			cmp esi, ecx
			jna loopEnd2
			// проверка двух разрядов
			mov ebx, numeral[4 * esi]
			mov edx, numeral[4 * ecx]
			cmp ebx, edx
			jne notSymmetric
			inc ecx
			dec esi
			jmp loopBegin2
			loopEnd2 :
		mov result, 1
			jmp symmetric

			notSymmetric :
		mov result, 0
			symmetric :
	}

	return result;
}

int NumResearch::figureSum(int n) {
	int sum;
	_asm {
		mov eax, n

		cmp eax, 0
		jg gr
		neg eax

		gr:

		mov ebx, 0
		mov ecx, 10

		loopBegin:
		cmp eax, 0
			jna loopEnd
			cdq
			div ecx
			add ebx, edx
			jmp loopBegin
			loopEnd :

		mov sum, ebx
	}
	return sum;
}

int NumResearch::evenNumeralAmount(int n) {
	int amount;
	_asm {
		mov eax, n

		cmp eax, 0
		jg gr
		neg eax

		gr :

		mov ebx, 0
		mov ecx, 10

		loopBegin:
		cdq
			div ecx

			test edx, 1
			jnz odd
			inc ebx
			odd :

		cmp eax, 0
			jna loopEnd
			jmp loopBegin
			loopEnd :

		mov amount, ebx
	}
	return amount;
}