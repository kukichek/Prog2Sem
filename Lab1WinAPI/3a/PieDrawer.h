#include <cmath>
#include"FigureDrawer.h"
#pragma once

class PieDrawer : public FigureDrawer {
	const LPCSTR figureName = "Сектор";
	const int strSize = 6;
public:
	void redraw(HDC hDC, RECT rect) {
		POINT rBeginP, rEndP;
		rBeginP.x = rect.right;		rBeginP.y = (rect.top + rect.bottom) / 2;
		rEndP.x = rect.right;		rEndP.y = rBeginP.y - (rect.right - rect.left) / (2 * sqrt(3));

		Pie(hDC, rect.left, rect.top, rect.right, rect.bottom, rBeginP.x, rBeginP.y, rEndP.x, rEndP.y);
		TextOut(hDC, rect.left, rect.bottom, figureName, strSize);
	}
};
