#pragma once
#include<vector>
#include<algorithm>
#include"Student.h"

using namespace std;

class StudList {
	vector<Student> _vec;
	struct AverageBall {
		AverageBall(double _ball) : ball(_ball) {}
		bool operator() (Student cur);
	private:
		double ball;
	};
public:
	StudList(string nameOfFile);
	StudList(vector<Student> vecStud);
	int count(double _ball);
	void printListGroup(int _group);
	StudList reverse();
	void sort(bool Comp(const Student &first, const Student &last));
	void show();
};