/*
Создать vector<int>, считать в него список чисел из текстового файла. Выполнить, не используя циклов:
	поиск наибольшего значения;
	подсчет количества чисел, равных заданному числу;
	подсчет количества чисел, удовлетворяющих условию, например, «больше, чем 15»;
	подсчет общего количества чисел;
	подсчет суммы чисел;
	подсчет среднего арифметического чисел.
Подсказка! Использовать алгоритмы max_element, count, count_if, accumulate.

Гамезо Валерия, 1 курс, информатика
*/

#include<iostream>
#include<iomanip>
#include<fstream>
#include"Numbers.h"
#include"Condition.h"
#include"Extractor.h"

void formatOut(string sentence) {
	cout << setw(40) << setiosflags(std::ios::left) << sentence;
	return;
}

using namespace std;

int main() {
	string nameOfFile = "input.txt";

	try {
		Extractor _extractor(nameOfFile);
		Numbers nums = _extractor.createNumList();

		formatOut("Max element: ");
		cout << nums.findMax() << "\n";

		int temp;
		formatOut("Enter, please, a number: ");
		cin >> temp;
		cout << "An amount of numbers equal to " << temp << ":\t" << nums.countEqual(temp) << "\n";

		formatOut("An amount of odd numbers: ");
		cout << nums.countCond(Condition()) << "\n";

		formatOut("An amount of numbers: ");
		cout << nums.amount() << "\n";

		formatOut("Sum of numbers: ");
		cout << nums.sum() << "\n";

		formatOut("An average of numbers: ");
		cout << nums.average() << endl;
	}
	catch (string error) {
		cout << error << endl;
	}

	system("pause");

	return 0;
}