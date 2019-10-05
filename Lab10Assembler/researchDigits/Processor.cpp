#include"Processor.h"

Processor::Processor() {
	cout << "Enter, please, a number: ";
	cin >> num;
}

void Processor::operator() () {
	DigitCounter counter(num);
	cout << "Amount of sign characters is " << counter.getSignCharacters() << endl;
	cout << "Amount of On-bits is " << counter.getOnBits() << endl;
}