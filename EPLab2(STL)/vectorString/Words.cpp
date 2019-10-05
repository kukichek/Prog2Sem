#include<iostream>
#include<fstream>
#include<set>
#include"fileLib.h"
#include"Words.h"

bool Words::Comp::operator() (string word) {
	return word[0] == _l;
}

void Words::Print::operator() (string word) {
	cout << word << "\n";
}

Words::Words(string nameOfFile) {
	nameOfFile = "content\\" + nameOfFile;
	ifstream fin(nameOfFile);

	try {
		string error;
		if (!isValidFile(fin, error)) throw error;
	}
	catch (string error) {
		cout << error << endl;
	}

	string temp;
	while (fin >> temp) {
		_vec.push_back(temp);
	}
}

void Words::wordSort() {
	sort(_vec.begin(), _vec.end());
}

void Words::show(vector<string>::iterator begin, vector<string>::iterator end) {
	for_each(begin, end, Print());
}

void Words::showLetterWords(char letter) {
	vector<string>::iterator begin = find_if(_vec.begin(), _vec.end(), Comp(letter));
	vector<string>::iterator end = find_if_not(begin, _vec.end(), Comp(letter));
	if (begin != end) {
		cout << "Words start with \"" << letter << "\" are:\n";
		show(begin, end);
	}
	else {
		cout << "There is no words start with \"" << letter << "\"\n";
	}
}

void Words::deleteWords(char letter) {
	vector<string>::iterator begin = find_if(_vec.begin(), _vec.end(), Comp(letter));
	vector<string>::iterator end = find_if_not(begin, _vec.end(), Comp(letter));
	_vec.erase(begin, end);
}

int Words::numberDifWords() {
	set<string> _set(_vec.begin(), _vec.end());
	cout << "Words without reduplication:\n";
	for_each(_set.begin(), _set.end(), Print());
	return _set.size();
}

map<string, int> Words::dupli() {
	multiset<string> _set(_vec.begin(), _vec.end());
	map<string, int> _map;
	for (auto i = _set.begin(); i != _set.end(); ) {
		int amount = _set.count(*i);
		_map.emplace(*i, amount);
		i = _set.upper_bound(*i);
	}
	return _map;
}