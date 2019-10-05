#pragma once
#include <windows.h>
#include "Schedule.h"

//class Drawer {
//	vector<string> weekDays = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота" };
//
//	HDC *hDC;
//	HWND *hwnd;
//	vector<int[3]> colors;
//public:
//	Drawer(HDC *_HDC, HWND *_HWND) : hDC(_HDC), hwnd(_HWND) {}
//	void operator() (Schedule *_schedule) {
//		RECT rect;
//		GetClientRect(*hwnd, &rect);
//
//		rect.left = 0;
//		rect.right = 50;
//		for (int i = 0; i < _schedule->daysAm; ++i) {
//			rect.top = 0;
//			rect.bottom = 20;
//
//			DrawText(*hDC, weekDays[i].c_str(), weekDays[i].size(), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
//
//			for (int j = 0; j < _schedule->maxClassAm; ++j) {
//				rect.top += 50;
//				rect.bottom += 50;
//
//
//			}
//			rect.left += 50;
//			rect.right += 50;
//		}
//	}
//};