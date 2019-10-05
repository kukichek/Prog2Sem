#pragma once
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

class Words {
	static vector<string> _vec;
	class Comp {
		char _l;
	public:
		Comp(char letter) : _l(letter) {}
		bool operator() (string word);
	};
	struct Print {
		void operator() (string word);
	};
public:
	Words(string nameOfFile);
	void wordSort();
	static void show(vector<string>::iterator begin = _vec.begin(), vector<string>::iterator end = _vec.end());
	void showLetterWords(char letter);
	void deleteWords(char letter);
	int numberDifWords();
	map<string, int> dupli();
};