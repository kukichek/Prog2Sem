#include"DigitCounter.h"

void DigitCounter::countSignCharacters() {
	int n = num;
	_asm {
		mov eax, n
		mov esi, 0
		mov ecx, 32

		cmp eax, 0
		je _nul
		jg beginLoop

		neg eax

		beginLoop :
		shl eax, 1

			jc endLoop

			inc esi
			loop beginLoop

		_nul:

		mov esi, 31

		endLoop :

		mov n, esi
	}
	offset = n;
}

void DigitCounter::countOnBits() {
	int off = offset;
	int n = num;
	_asm {
		mov eax, n
		mov ebx, off
		mov ecx, 32
		sub ecx, ebx

		mov esi, 0

		cmp eax, 0
		je zero
		jg beginLoop

		neg eax

beginLoop:	shr eax, 1
			jnc notOnBit

			inc esi

notOnBit:	loop beginLoop

zero:		mov off, esi
	}
	onbit = off;
}

DigitCounter::DigitCounter(int n) : num(n) {
	countSignCharacters();
	countOnBits();
}

void DigitCounter::set(int n) {
	num = n;
	countSignCharacters();
	countOnBits();
}

int DigitCounter::getSignCharacters() {
	return 32 - offset;
}

int DigitCounter::getOnBits() {
	return onbit;
}