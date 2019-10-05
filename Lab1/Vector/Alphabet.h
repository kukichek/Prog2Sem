#include<vector>
#include<string>
#pragma once

using namespace std;

class Alphabet {
private:
	vector<char> v;
public:
	Alphabet();
	void showInOrder(const string title = "Letters of an alphabet in order:");
	void showInReverseOrder(const string title = "Letters of an alphabet in reverse order:");
};