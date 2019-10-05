/*
2.	Из заданной строки исключить символы, расположенные между круглыми скобками.
*/

#include<iostream>

extern "C" int _fastcall getLength(char* str);
extern "C" void _fastcall delBraces(int n, char *str);

const int maxL = 100000;

using namespace std;

int main() {
	char initS[maxL];
	gets_s(initS);
	int n = getLength(initS);
	delBraces(n, initS);
	cout << "Final string: " << initS << endl;

	system("pause");

	return 0;
}