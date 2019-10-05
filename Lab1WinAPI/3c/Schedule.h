#pragma once
#include<vector>
#include<map>
#include<utility>
#include"Lesson.h"
#include"Drawer.h"

using namespace std;

class Schedule {
	/*friend Drawer;*/
	typedef int room;
	typedef int lessonIndex;

	map <string, int> lessonIndexes;
	pair <lessonIndex, room> indexes[6][5];
	int maxClassAm;
	int daysAm;
public:
	Schedule();
	void FillSchedule(vector<vector<Lesson> > _schedule);
};