#include<iostream>
#include"GetArray.h"

using namespace std;

extern "C" int _fastcall findMaxRow(int n, int **arr);
extern "C" int _fastcall findMinRow(int n, int **arr);
extern "C" void _cdecl swapRows(int n, int minRow, int maxRow, int **arr);

int main() {
	try {
		string fileName;

		cout << "Enter, please, a name of file\n";
		cin >> fileName;

		GetArray getter(fileName);
		int n = getter.getSize();

		int **arr = new int*[n];
		for (int i = 0; i < n; ++i) {
			arr[i] = new int [n];
		}

		getter(n, arr);

		cout << findMaxRow(n, arr) << endl;
	}
	catch (string error) {
		cout << error << endl;
	}

	system("pause");

	return 0;
}