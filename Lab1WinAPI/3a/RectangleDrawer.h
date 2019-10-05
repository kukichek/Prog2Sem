#include"FigureDrawer.h"
#pragma once

class RectangeDrawer : public FigureDrawer {
	const LPCSTR figureName = "Прямоугольник";
	const int strSize = 13;
public:
	void redraw(HDC hDC, RECT rect) {
		Rectangle(hDC, rect.left, rect.top, rect.right, rect.bottom);
		TextOut(hDC, rect.left, rect.bottom, figureName, strSize);
	}
};