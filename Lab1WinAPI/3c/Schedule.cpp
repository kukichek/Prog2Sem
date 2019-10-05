#include "Schedule.h"

Schedule::Schedule() {
	maxClassAm = 0;
	daysAm = 0;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 6; ++j) {
			indexes[i][j].first = 0;
			indexes[i][j].second = 0;
		}
	}
}

void Schedule::FillSchedule(vector<vector<Lesson> > _schedule) {
	for (int i = 0; i < _schedule.size(); ++i) {
		int day = _schedule[i][0]._d;
		for (int j = 0; j < _schedule[i].size(); ++j) {
			int n = lessonIndexes.size();
			maxClassAm = max(maxClassAm, n);
			lessonIndexes.emplace(_schedule[i][j].lessonName, n + 1);
			indexes[day][_schedule[i][j]._n].first = lessonIndexes[_schedule[i][j].lessonName] * _schedule[i][j].lecPrac;
			indexes[day][_schedule[i][j]._n].second = _schedule[i][j].room;
		}
	}
	daysAm = _schedule[_schedule.size() - 1][0]._d + 1;
}