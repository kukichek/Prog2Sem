#include"Processor.h"

Processor::Processor() {
	a = 0;
}

int Processor::getOperand() {
	std::cout << "Enter, please, an integer number: ";
	std::cin >> a;
	return a;
}

void Processor::operator() () {
	std::cout << a << "^5 + " << a << "^3 + " << a << " = ";
	std::cout << Operation()(a) << std::endl;
}