#include"GetPow.h"

int GetPow::operator() (int a) {
	int n;
	__asm {
		mov ecx, 0
		mov eax, a

		_begin :
		jc _end

			imul eax, a
			inc ecx
			jmp _begin

			_end :
		mov n, ecx
	}
	return n;
}