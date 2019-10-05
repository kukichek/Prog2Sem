#pragma once
#include <string>

using namespace std;

struct Lesson {
	int _d, _n, room, lecPrac; // лекция коэффицент - 1, практика коэффицент - -1
	string lessonName;
};