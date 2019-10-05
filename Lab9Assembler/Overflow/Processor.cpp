#include"Processor.h"

void Processor::setBase() {
	cout << "Enter, please, a base: ";
	cin >> a;
}

void Processor::operator() () {
	cout << "A pow of a number " << a << " that fits in 32 digits is " << GetPow()(a) << endl;
}