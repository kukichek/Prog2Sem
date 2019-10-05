#include"function.h"

bool CompName(const Student &first, const Student &last) {
	return (first.name < last.name);
}

bool CompGroupName(const Student &first, const Student &last) {
	if (first.group == last.group) return (first.name < last.name);
	return (first.group < last.group);
}

bool CompAvBall(const Student &first, const Student &last) {
	return (first.ball < last.ball);
}

double getBall() {
	double ball;
	cout << "Enter, please, an average ball:\t";
	cin >> ball;
	return ball;
}

int getGroup() {
	int group;
	cout << "Enter, please, a group:\t";
	cin >> group;
	return group;
}