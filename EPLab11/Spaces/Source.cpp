#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

extern "C" int _fastcall getLength(char* str);
extern "C" int _fastcall delFSpaces(int n, char* str);
extern "C" int _fastcall delLSpaces(int n, char* str);
extern "C" void _fastcall delSpaces(int n, char* str);
extern "C" int _fastcall countWords(int n, char* str);

const int maxL = 100000;

int main() {
	char initS[maxL];
	gets_s(initS);
	int n = getLength(initS);

	n = delFSpaces(n, initS);
	n = delLSpaces(n, initS);
	delSpaces(n, initS);
	cout << "Final string: " << initS << endl;
	n = getLength(initS);
	cout << "Amount of words: " << countWords(n, initS) << endl;

	system("pause");

	return 0;
}