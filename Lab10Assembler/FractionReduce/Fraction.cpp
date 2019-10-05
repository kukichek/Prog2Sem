#include"Fraction.h"

int Fraction::gcd(int a, int b) {
	int _gcd;
	_asm {
		mov eax, a
		mov ebx, b

		cmp eax, ebx
		jae beginLoop

		mov eax, b
		mov ebx, a

		beginLoop :

		cmp ebx, 0
			je endLoop

			cdq
			idiv ebx

			mov ecx, ebx
			mov ebx, edx
			mov eax, ecx

			jmp beginLoop

			endLoop :

		mov _gcd, eax
	}

	return _gcd;
}

void Fraction::reduce(int n) {
	int num = numenator, den = denominator;
	_asm {
		mov ecx, n
		mov eax, den
		cdq
		idiv ecx
		mov den, eax

		mov eax, num
		cdq
		idiv ecx
		mov num, eax
	}

	numenator = num;
	denominator = den;
}

Fraction::Fraction(int _num, int _den) : numenator(_num), denominator(_den) {
	string error = "Division by 0";
	if (_den == 0) throw error;

	int n = gcd(_num, _den);
	reduce(n);
}

ostream& operator<< (ostream &out, Fraction &obj) {
	out << obj.numenator;
	if (obj.denominator != 1) {
		cout << '/' << obj.denominator;
	}
	return out;
}

istream& operator>> (istream &in, Fraction &obj) {
	string line;
	string seps = " /";
	getline(in, line);

	obj.numenator = stoi(line);

	if (line.find_first_of(seps) != -1) {
		line = line.substr(line.find_first_of(seps) + 1);
		obj.denominator = stoi(line);
	} else {
		obj.denominator = 1;
	}

	string error = "Division by 0";
	if (obj.denominator == 0) throw error;

	int n = obj.gcd(obj.numenator, obj.denominator);
	obj.reduce(n);

	return in;
}