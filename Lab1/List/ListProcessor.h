#include<list>
#include<string>
#include<iostream>
#include<fstream>
#include<algorithm>
#pragma once

using namespace std;

class ListProcessor {
private:
	static list<string> words;

	struct Initial {
		Initial(char _c) : c(_c) {}
		bool operator () (string word);
	private:
		char c;
	};
	struct NotInitial {
		NotInitial(char _c) : c(_c) {}
		bool operator () (string word);
	private:
		char c;
	};
public:
	ListProcessor(string nameOfInitFile);
	void listSort();
	void show(string title, list<string>::const_iterator begin = words.begin(),
							list<string>::const_iterator end = words.end());
	void givenLetter();
	void listErase(list<string>::const_iterator begin,
				   list<string>::const_iterator end);
};
