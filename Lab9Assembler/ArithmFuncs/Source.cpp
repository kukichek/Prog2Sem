#include"Processor.h"

using namespace std;

int main() {
	Processor proc;
	proc();
	proc.~Processor();

	system("pause");

	return 0;
}