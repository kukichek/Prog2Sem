#include<fstream>
#include"Greater2.h"
#pragma once

using namespace std;

template<class Container>
class NumProc {
private:
	Container cont;
public:
	NumProc(string nameOfFile);
	void count(int given);
	template<class Condition> void count_if();
	void size();
	void accumulate();
	void arith();
	void showType(const char* type);
};

template<class Container> NumProc<Container>::NumProc(string nameOfFile) {
	ifstream fin(nameOfFile);
	int n;
	while (fin >> n) {
		cont.push_back(n);
	}
}

template<class Container> void NumProc<Container>::count(int given) {
	cout << "An amount of numbers equal to " << given << " is ";
	cout << std::count(cont.begin(), cont.end(), given) << endl;
}

template<class Container> template<class Condition> void NumProc<Container>::count_if() {
	cout << "An amount of numbers greater than 2 is ";
	cout << std::count_if(cont.begin(), cont.end(), Condition()) << endl;
}

template<class Container> void NumProc<Container>::size() {
	cout << "An amount of numbers is ";
	cout << cont.size() << endl;
}

template<class Container> void NumProc<Container>::accumulate() {
	cout << "A sum of numbers is ";
	cout << std::accumulate(cont.begin(), cont.end(), 0) << endl;
}

template<class Container> void NumProc<Container>::arith() {
	cout << "A arithmetical mean of numbers is ";
	cout << 1. * std::accumulate(cont.begin(), cont.end(), 0) / cont.size() << endl;
}

template<class Container> void NumProc<Container>::showType(const char* type) {
	cout << "-----" << type << "-----\n";
}