/*
Создать vector<string>, считать в него список слов из текстового файла. Выполнить:
	сортировку списка в лексикографическом порядке;
	печать отсортированного списка;
	печать элементов списка, начинающихся на заданную букву;
	удаление элементов списка на заданную букву;
	печать списка после удаления элементов;
	вычислить и вывести список различных слов (set);
	вычислить и вывести количество повторений каждого слова (map<string,int>).

Гамезо Валерия, 1 курс, информатика
*/

#include<utility>
#include"Words.h"
#include"func.h"

using namespace std;

vector<string> Words::_vec;

int main() {
	string name = "input.txt";
	Words words(name);

	words.wordSort();
	cout << "Words:\n";
	words.show();
	char letter = getLetter();
	words.showLetterWords(letter);
	words.deleteWords(letter);
	cout << "Words after deleteing:\n";
	words.show();
	cout << "The number of different words is " << words.numberDifWords() << endl;

	map<string, int> _map = words.dupli();
	cout << "The number of words and their reduplication:\n";
	for_each(_map.begin(), _map.end(), [](pair<string, int> el) {cout << el.first << '\t' << el.second << '\n'; });

	system("pause");

	return 0;
}