#include<iostream>
#include<fstream>
#include"StudList.h"
#include"fileLib.h"

bool StudList::AverageBall::operator() (Student cur) {
	return cur.ball == ball;
}

StudList::StudList(string nameOfFile) {
	nameOfFile = "content\\" + nameOfFile;
	ifstream fin(nameOfFile);

	try {
		string error;
		if (!isValidFile(fin, error)) throw error;
	}
	catch (string error) {
		cout << error << endl;
	}

	Student temp;
	while (fin >> temp) {
		_vec.push_back(temp);
	}
}

StudList::StudList(vector<Student> vecStud) {
	_vec = vecStud;
}

int StudList::count(double _ball) {
	int amount = count_if(_vec.begin(), _vec.end(), AverageBall(_ball));
	return amount;
}

void StudList::printListGroup(int _group) {
	for (auto i : _vec) {
		if (i.group == _group) {
			cout << i << endl;
		}
	}
}

StudList StudList::reverse() {
	vector<Student> out(_vec.rbegin(), _vec.rend());
	return StudList(out);
}

void StudList::sort(bool Comp(const Student &first, const Student &last)) {
	std::sort(_vec.begin(), _vec.end(), Comp);
}

void StudList::show() {
	for (auto i : _vec) {
		cout << i << endl;
	}
}