#include"ListProcessor.h"

bool ListProcessor::Initial::operator () (string word) {
	return word[0] == c;
}
bool ListProcessor::NotInitial::operator () (string word) {
	return word[0] != c;
}
ListProcessor::ListProcessor(string nameOfInitFile) {
	ifstream fin(nameOfInitFile);
	string curWord;
	while (fin >> curWord) {
		words.push_back(curWord);
	}
}
void ListProcessor::listSort() {
	words.sort();
}
void ListProcessor::show(string title, list<string>::const_iterator begin,
									   list<string>::const_iterator end) {
	cout << title << endl;
	for (auto it = begin; it != end; ++it) {
		cout << (*it) << '\n';
	}
}
void ListProcessor::givenLetter() {
	char letter;
	cout << "Enter, please, a letter\n";
	cin >> letter;
	list<string>::iterator p1 = find_if(words.begin(), words.end(), Initial(letter));
	list<string>::iterator p2 = find_if(p1, words.end(), NotInitial(letter));
	if (p1 == p2) {
		cout << "There is not any word that starts with a letter \'" << letter << "\'\n";
	}
	else {
		show("Words thar start with a given letter are:", p1, p2);
	}
	listErase(p1, p2);
}
void ListProcessor::listErase(list<string>::const_iterator begin,
	list<string>::const_iterator end) {
	words.erase(begin, end);
}