/*
Использовать множества с элементами типа string и операции над ними.

В озере водятся рыбы нескольких видов. N рыбаков поймали экземпляры, представляющие некоторые из имеющихся видов. Вывести в файл информацию:
−	какие виды рыб есть у каждого рыбака;
−	рыб каких видов выловил хотя бы один рыбак;
−	какие рыбы есть в озере, но не в улове любого из рыбаков.
Во входном файле представлена следующая информация:
1)	что водится в озере;
2)	улов каждого рыбака, в котором могут присутствовать несколько экземпляров одного вида.
*/

#include<iostream>
#include<fstream>
#include<set>
#include<string>
#include<vector>
#include"fileLib.h"

using namespace std;

struct Fish {
	set<string> _set;
	friend istream& operator>> (istream &in, Fish &_fish) {
		string fish;
		while (in >> fish) {
			_fish._set.insert(fish);
			if (in.get() == '\n') break;
		}
		return in;
	}
};

struct FishList {
	vector<set<string> > _vec;
	FishList() {}
	FishList(string nameOfFile) {
		nameOfFile = "content\\" + nameOfFile;
		ifstream fin(nameOfFile);

		try {
			string error;
			if (!isValidFile(fin, error)) throw error;
		}
		catch (string error) {
			cout << error << endl;
		}

		Fish temp;
		while (fin >> temp) {
			_vec.push_back(temp._set);
			temp._set.clear();
		}
		_vec.push_back(temp._set);
	}
	int size() {
		return _vec.size();
	}
	set<string> operator[] (int i) {
		return _vec[i];
	}
	vector<set<string> >::iterator begin() {
		return _vec.begin();
	}
	vector<set<string> >::iterator end() {
		return _vec.end();
	}
	void insert(vector<set<string> >::iterator first, vector<set<string> >::iterator last) {
		_vec.insert(_vec.begin(), first, last);
	}
};

class Catch {
	multiset<string> averageFishCatch;
	FishList fisherMen;
	vector<string> fishCaught;
	vector<string> fishUncaught;
	void calc() {
		for (auto i = averageFishCatch.begin(); i != averageFishCatch.end();) {
			int score = averageFishCatch.count(*i);
			if (score == 1) {
				fishUncaught.push_back(*i);
			}
			if (score == fisherMen.size() + 1) {
				fishCaught.push_back(*i);
			}
			i = averageFishCatch.upper_bound(*i);
		}
	}
public:
	Catch(FishList _fishList) {
		vector<set<string> >::iterator first = _fishList.begin();
		first++;
		fisherMen.insert(first, _fishList.end());
		for (int i = 0; i < _fishList.size(); ++i) {
			averageFishCatch.insert(_fishList[i].begin(), _fishList._vec[i].end());
		}
		calc();
	}
	void showFishermenSpecies() {
		for (int i = 0; i < fisherMen.size(); ++i) {
			cout << "Species of the " << i + 1 << " fisherman are:\n";
			for (auto j : fisherMen[i]) {
				cout << j << '\t';
			}
			cout << endl;
		}
	}
	void showCaught() {
		cout << "Species caught by every fisherman are:\n";
		for (string i : fishCaught) {
			cout << i << '\t';
		}
		cout << endl;
	}
	void showUncaught() {
		cout << "Species not caught by any fisherman are:\n";
		for (string i : fishUncaught) {
			cout << i << '\t';
		}
		cout << endl;
	}
};

int main() {
	FishList _fishlist("input.txt");
	Catch _catch(_fishlist);
	_catch.showFishermenSpecies();
	_catch.showCaught();
	_catch.showUncaught();

	system("pause");

	return 0;
}