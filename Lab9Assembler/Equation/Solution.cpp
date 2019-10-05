#include"Solution.h"

vector<pair<int, int> > Solution::operator() () {
	int xa, ya;
	vector<pair<int, int> > answer;

	__asm {
		mov ebx, 0		// ebx = 2x

		_begin:
		mov ch, 3
			cmp ebx, 50
			ja _end

			mov eax, 50
			sub eax, ebx
			cdq
			div ch
			test ah, 11b
			jnz not_root

			// вычисление x {
			shr ebx, 1
			mov xa, ebx
			shl ebx, 1
			// вычисление x }

			// вычисление y {
			mov eax, 50
			sub eax, ebx
			cdq
			div ch
			mov ya, eax
			// вычисление y }
	}

	answer.push_back(make_pair(xa, ya));

	_asm {
	not_root:
		add ebx, 2

			jmp _begin
			_end :
	}

	answer.shrink_to_fit();
	return answer;
}