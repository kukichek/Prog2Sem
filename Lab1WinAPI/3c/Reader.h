#pragma once
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include"Lesson.h"
#include"Schedule.h"
#include"fileLib.h"

using namespace std;

class Reader {
	ifstream in;
	string seps = " :;()\t";

	int getDay(string &cur);
	vector<string> separateString(string cur);
	vector<Lesson> extractLessons(vector<string> lessonStr, int _d);
public:
	Reader(string _fName);
	Schedule generateSchedule();
};