#include <windows.h>
#pragma once

class FigureDrawer {
public:
	virtual void redraw(HDC hDC, RECT rect) = 0;
};