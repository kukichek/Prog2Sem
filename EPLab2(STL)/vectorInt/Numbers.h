#pragma once
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Numbers {
private:
	vector<int> _vec;
public:
	Numbers();

	void push(int el);

	int findMax();

	int countEqual(int el);

	template<class T>
	int countCond(T Cond) {
		return count_if(_vec.begin(), _vec.end(), Cond);
	}

	int amount();

	int sum();

	double average();
};
