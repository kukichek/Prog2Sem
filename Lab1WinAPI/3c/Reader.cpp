#include"Reader.h"

int Reader::getDay(string &cur) {
	map<string, int> weekDays = { make_pair("Понедельник", 0),
								make_pair("Вторник", 1),
								make_pair("Среда", 2),
								make_pair("Четверг", 3),
								make_pair("Пятница", 4),
								make_pair("Суббота", 5), };
	int beginPos = 0, endPos = 0;
	beginPos = cur.find_first_not_of(seps, endPos);
	endPos = cur.find_first_of(seps, beginPos);
	int day = weekDays[cur.substr(beginPos, endPos - beginPos)];
	cur.erase(beginPos, endPos - beginPos);
	return day;
}

vector<string> Reader::separateString(string cur) {
	vector<string> lessonStr;
	int pos = 0;
	pos = cur.find(';');
	while (pos != string::npos) {
		lessonStr.push_back(cur.substr(0, pos));
		cur.erase(0, pos + 1);
		pos = cur.find(';');
	}
	lessonStr.push_back(cur.substr(0, pos));
	return lessonStr;
}

vector<Lesson> Reader::extractLessons(vector<string> lessonStr, int _d) {
	map <string, int> indexName = { make_pair("Первая", 0),
									make_pair("Вторая", 1),
									make_pair("Третья", 2),
									make_pair("Четвертая", 3),
									make_pair("Пятая", 4) };
	map <string, int> boolIndex = { make_pair("Лекция", 1),
									make_pair("Практика", -1) };
	vector<Lesson> lessons(lessonStr.size());
	for (int i = 0; i < lessonStr.size(); ++i) {
		lessons[i]._d = _d;

		int beginPos = 0, endPos = 0;
		beginPos = lessonStr[i].find_first_not_of(seps, endPos);
		endPos = lessonStr[i].find_first_of(seps, beginPos);
		string lessonNumber = lessonStr[i].substr(beginPos, endPos - beginPos);
		lessons[i]._n = indexName[lessonNumber];

		beginPos = lessonStr[i].find_first_not_of(seps, endPos);
		if (lessonStr[i].find('(') != string::npos) {
			endPos = lessonStr[i].find('(');
			lessons[i].lessonName = lessonStr[i].substr(beginPos, endPos - beginPos);
			beginPos = lessonStr[i].find_first_not_of(seps, endPos);
			endPos = lessonStr[i].find_first_of(seps, beginPos);
			lessons[i].lecPrac = boolIndex[lessonStr[i].substr(beginPos, endPos - beginPos)];
			beginPos = lessonStr[i].find_first_not_of(seps, endPos);

		}
		else {
			endPos = lessonStr[i].find_first_of("0123456789", beginPos);
			lessons[i].lessonName = lessonStr[i].substr(beginPos, endPos - beginPos);
			lessons[i].lecPrac = 1;
			beginPos = endPos;
		}
		lessons[i].lessonName = lessons[i].lessonName.substr(0, lessons[i].lessonName.find_last_not_of(seps) + 1);
		lessons[i].room = stoi(lessonStr[i].substr(beginPos, -1));
	}
	return lessons;
}

Reader::Reader(string _fName) {
	in.open(_fName);
	string error;
	if (!isValidFile(in, error)) {
		throw error;
	}
}

Schedule Reader::generateSchedule() {
	string cur;
	vector<vector<Lesson> > weekSchedule;
	while (getline(in, cur)) {
		int day = getDay(cur);
		vector<Lesson> daySchedule = extractLessons(separateString(cur), day);
		weekSchedule.push_back(daySchedule);
	}
	Schedule schedule;
	schedule.FillSchedule(weekSchedule);
	return schedule;
}