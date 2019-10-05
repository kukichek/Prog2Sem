#include"FigureDrawer.h"
#pragma once

class RombusDrawer : public FigureDrawer {
	const LPCSTR figureName = "Ромб";
	const int strSize = 4;
	const int pointSize = 4;
	POINT points[4];
public:
	void redraw(HDC hDC, RECT rect) {
		points[0].x = rect.left;						points[0].y = (rect.top + rect.bottom) / 2;
		points[1].x = (rect.left + rect.right) / 2;		points[1].y = rect.top;
		points[2].x = rect.right;						points[2].y = (rect.top + rect.bottom) / 2;
		points[3].x = (rect.left + rect.right) / 2;		points[3].y = rect.bottom;

		Polygon(hDC, points, pointSize);
		TextOut(hDC, rect.left, rect.bottom, figureName, strSize);
	}
};
