/*
Создайте vector<char>, содержащий буквы в алфавитном порядке. 
Распечатайте элементы этого вектора в прямом и обратном порядках.

Гамезо Валерия, 1 курс, информатика
*/

#include"Alphabet.h"

using namespace std;

int main() {
	Alphabet _vector;
	_vector.showInOrder();
	_vector.showInReverseOrder();

	system("pause");

	return 0;
}