#include"Out.h"

void Out::operator() () {
	vector<pair<int, int> > a = Solution()();

	cout << "Solutions of an equation 2x + 3y = 50 in positive integer numbers are:\n";
	cout << "x\ty\n";

	for (auto i : a) {
		cout << i.first << "\t" << i.second << "\n";
	}
	a.~vector();
}