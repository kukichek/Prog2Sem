/*
�������� 3 ��������� ����������, �������� � ���� ����� �� ���������� �����. ���������, �� ��������� ������:
-	������� ���������� �����, ������ ���������;
-	������� ���������� �����, ��������������� �������, ��������, �������, ��� 15�;
-	������� ������ ���������� �����;
-	������� ����� �����;
-	������� �������� ��������������� �����.

���������!!! ������������ ��������� count, count_if, accumulate.
��� ������ ���������� ������ ��������� ���� �� ����� ���������� 3?

������ �������, 1 ����, 1 ������
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<algorithm>
#include<numeric>

#include"NumProc.h"

using namespace std;

int main() {
	NumProc < vector<int> > first("content/input.txt");
	first.showType("vector");
	first.count(5);
	first.count_if<Greater2>();
	first.size();
	first.accumulate();

	NumProc < list<int> > second("content/input.txt");
	second.showType("list");
	second.count(5);
	second.count_if<Greater2>();
	second.size();
	second.accumulate();

	NumProc < deque<int> > third("content/input.txt");
	third.showType("deque");
	third.count(5);
	third.count_if<Greater2>();
	third.size();
	third.accumulate();

	system("pause");

	return 0;
}