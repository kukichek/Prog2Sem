#include"FigureDrawer.h"
#pragma once

class EllipseDrawer : public FigureDrawer {
	const LPCSTR figureName = "έλλθορ";
	const int strSize = 6;
public:
	void redraw(HDC hDC, RECT rect) {
		Ellipse(hDC, rect.left, rect.top, rect.right, rect.bottom);
		TextOut(hDC, rect.left, rect.bottom, figureName, strSize);
	}
};