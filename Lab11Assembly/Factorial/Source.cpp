/*
1.	Длинное число представлено как массив, содержащий цифры. Найти факториал заданного длинного числа.
*/

#include<iostream>
#include<algorithm>
#include<windows.h>
#include"Processor.h"

using namespace std;

const int MAX_SIZE = 1000 * 1000 * 100;

extern "C" DWORD _fastcall isOne(int *num);
extern "C" void _fastcall decrement(int *num);
extern "C" void _fastcall multiply(int *ans, int *mul);

void out(int *num) {
	for (int i = *num; i > 0; --i) {
		cout << num[i];
	}

	cout << endl;

	return;
}

int main() {
	try {
		Processor proc("input.txt");
		int *factor = proc();

		int *ans = new int[MAX_SIZE];
		ans[0] = 1;
		ans[1] = 1;

		while (!isOne(factor)) {
			multiply(ans, factor);
			decrement(factor);
		}

		out(ans);
	}
	catch (string err) {
		cout << err << endl;
	}

	system("pause");

	return 0;
}