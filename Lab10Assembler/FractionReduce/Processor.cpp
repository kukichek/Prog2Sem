#include"Processor.h"

void Processor::operator() () {
	cout << "Enter, please, a fraction:\n";
	try {
		cin >> frac;
		cout << "A fraction after reduce is " << frac << endl;
	}
	catch (string error) {
		cout << error << endl;
	}
}