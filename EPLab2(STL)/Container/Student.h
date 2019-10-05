#pragma once
#include<string>

using namespace std;

struct Student {
	string name;
	int group;
	double ball;
	friend istream& operator>> (istream &in, Student &_stud);
	friend ostream& operator<< (ostream &out, Student &_stud);
};