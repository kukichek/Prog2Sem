#include<iostream>
#include<string>

using namespace std;

extern "C" int _fastcall len(char *romNum);
extern "C" int _cdecl countRomNum(int len, char *romNum);
extern "C" bool _stdcall isCorStr(int len, char *romNum);

const int MAXLEN = 1000 * 1000;

int main() {
	string in;
	cin >> in;
	int ans;

	int size = len(const_cast<char*>(in.c_str()));
	if (isCorStr(size, const_cast<char*>(in.c_str()))) {
		cout << "String is correct\n";
		ans = countRomNum(size, const_cast<char*>(in.c_str()));
		cout << in << " = " << ans << endl;
	}
	else {
		cout << "String is uncorrect\n";
	}

	system("pause");

	return 0;
}