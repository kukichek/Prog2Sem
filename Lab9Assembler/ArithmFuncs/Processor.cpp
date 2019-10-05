#include"Processor.h"

void Processor::setOperIndex() {
	do {
		cout << "Enter, plaese, an index of operation you want to use:\n";
		cout << "0 - substraction;\n";
		cout << "1 - multiplication;\n";
		cout << "2 - getting incomplete quotient;\n";
		cout << "3 - getting remainder;\n";
		cin >> operI;
	} while (operI > 3 || operI < 0);
}

void Processor::setOperands() {
	cout << "Enter, please, two integer numbers;\n";
	cin >> a >> b;
}

Processor::Processor() {
	setOperIndex();
	setOperands();
}

void Processor::operator() () {
	Operation* operation = opList[operI];
	try {
		int result = (*operation)(a, b);
		cout << "The result of " << operation->operName << " is " << result << endl;
	}
	catch (string error) {
		cout << error << endl;
	}
	delete operation;
}

Processor::~Processor() {
	opList.~OperationList();
}