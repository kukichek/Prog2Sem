/*
struct SStud{char name[20]; int group; double ball;};
�������� ���������, �������:
-	��������� �������� � ��������� �� ���������� ����� � ���������� ���������;
-	������� ���������� ��������� � �������� ������;
-	������� ������ ��������� �� �������� ������;
-	�������� �������� � ������ ������, � ������� ������ ������� ������������ ��������� �� ��������;
-	��������� �������� ������: �� �������, �� ������ � �������, �� �������� �����.
*/

#include"function.h"
#include"StudList.h"

using namespace std;

int main() {
	StudList students("input.txt");
	double ball = getBall();
	cout << "The number or student with average ball equal to " << ball << " is:\t" << students.count(ball) << endl;
	int group = getGroup();
	cout << "The list of students from the " << group << " group is:\n";
	students.printListGroup(group);
	cout << "List of students in reverse order is:\n";
	StudList reverseStudents = students.reverse();
	reverseStudents.show();
	cout << "List of students sorted by name is:\n";
	students.sort(CompName); students.show();
	cout << "List of students sorted by group and name is:\n";
	students.sort(CompGroupName); students.show();
	cout << "List of students sorted by average ball is:\n";
	students.sort(CompAvBall); students.show();

	system("pause");

	return 0;
}