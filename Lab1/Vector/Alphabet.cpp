#include<iostream>
#include"Alphabet.h"

Alphabet::Alphabet() {
	for (int i = 'a'; i <= 'z'; ++i) {
		v.push_back(i);
	}
}

void Alphabet::showInOrder(const string title) {
	cout << title << '\n';
	for (char i : v) {
		cout << i << ' ';
	}
	cout << '\n';
}

void Alphabet::showInReverseOrder(const string title) {
	cout << title << '\n';
	for (auto it = v.rbegin(); it != v.rend(); ++it) {
		cout << *it << ' ';
	}
	cout << '\n';
}