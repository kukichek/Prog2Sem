/*
2.	Определить является ли последовательность палиндромом.
*/

#include<iostream>
#include"GetArray.h"

const int MAXSIZE = 1000 * 1000;

extern "C" bool _fastcall isPal(int size, int *arr);

using namespace std;

int main() {
	try {
		string fileName;
		int *arr = new int[MAXSIZE];
		int size;

		cout << "Enter, please, a name of file\n";
		cin >> fileName;

		GetArray getter(fileName);
		size = getter(arr);

		if (isPal(size, arr)) {
			cout << "The sequence is a palindrome\n";
		} else {
			cout << "The sequence isn't a palindrome\n";
		}
	}
	catch (string error) {
		cout << error << endl;
	}

	system("pause");

	return 0;
}