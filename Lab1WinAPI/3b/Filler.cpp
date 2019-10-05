#include "Filler.h"

void Filler::operator() () {
	RECT rect;
	RedChange redChange;
	GreenChange greenChange;
	BlueChange blueChange;
	double x = 0;

	GetClientRect(*hwnd, &rect);

	while ((rect.right - rect.left > 2) && (rect.bottom - rect.top > 2)) {
		SelectObject(*hDC, GetStockObject(DC_BRUSH));
		SetDCBrushColor(*hDC, RGB(redChange(x), greenChange(x), blueChange(x)));
		x += 0.01;
		Rectangle(*hDC, rect.left, rect.top, rect.right, rect.bottom);
		rect.left += 1;
		rect.top += 1;
		rect.right -= 1;
		rect.bottom -= 1;
	}
}