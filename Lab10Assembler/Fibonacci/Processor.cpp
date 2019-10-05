#include"Processor.h"

void Processor::operator() () {
	cout << "Fibonacci sequence: 1, 1, 2, 3, 5, 8, 11...\n";
	cout << "An amount of numbers of Fibonacci sequence that fit in int is " << FibonacciNums()() << endl;
}