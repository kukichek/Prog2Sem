/*
Создайте list<string>, считайте в него список слов из текстового файла. Выполните:
-	сортировку списка;
-	печать отсортированного списка;
-	печать элементов списка, начинающихся на заданную букву
-	удаление элементов списка на заданную букву;
-	печать списка после удаления элементов.
Указание: найдите решение для удаления элементов списка, начинающихся на заданную букву
vector<string>::iterator p1=find_if(v.begin(), v.end(), initial('p'));
vector<string>::iterator p2=find_if(p1, v.end(), initial_not('p'));
v.erase(p1, p2);
здесь initial('p') - вами реализованная функция поиска слова на заданную букву.

Гамезо Валерия, 1 курс, информатика
*/

#include"ListProcessor.h"

using namespace std;

list<string> ListProcessor::words;

int main() {
	ListProcessor _list("content/input.txt");
	_list.listSort();
	_list.show("Sorted list:");
	_list.givenLetter();
	_list.show("Modified list:");

	system("pause");

	return 0;
}