#include"Processor.h"

Processor::Processor() {
	cout << "Enter, please, a number: ";
	cin >> n;
}
void Processor::operator() () {
	NumResearch res;
	cout << "A sum of figures of " << n << " is " << res.figureSum(n) << "\n";
	cout << "An amount of even figures of " << n << " is " << res.evenNumeralAmount(n) << "\n";
	cout << "A number " << n;
	if (res.isSymmetric(n)) {
		cout << " is symmetric";
	}
	else {
		cout << " isn't symmetric";
	}
	cout << endl;
}