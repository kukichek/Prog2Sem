#pragma once
#include <windows.h>
#include "RedChange.h"
#include "GreenChange.h"
#include "BlueChange.h"

class Filler {
	HDC *hDC;
	HWND *hwnd;
public:
	Filler(HDC *_HDC, HWND *_HWND) : hDC(_HDC), hwnd(_HWND) {}
	void operator() ();
};
