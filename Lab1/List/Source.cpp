/*
�������� list<string>, �������� � ���� ������ ���� �� ���������� �����. ���������:
-	���������� ������;
-	������ ���������������� ������;
-	������ ��������� ������, ������������ �� �������� �����
-	�������� ��������� ������ �� �������� �����;
-	������ ������ ����� �������� ���������.
��������: ������� ������� ��� �������� ��������� ������, ������������ �� �������� �����
vector<string>::iterator p1=find_if(v.begin(), v.end(), initial('p'));
vector<string>::iterator p2=find_if(p1, v.end(), initial_not('p'));
v.erase(p1, p2);
����� initial('p') - ���� ������������� ������� ������ ����� �� �������� �����.

������ �������, 1 ����, �����������
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