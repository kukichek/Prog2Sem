#undef UNICODE
#include <windows.h>
#include <vector>
#include <utility>
#include <string>
#include "Wnd.h"

using namespace std;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;

	Wind mainWnd("Trace", hInstance, nCmdShow, WndProc);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	static HDC hDC;
	static int x, y;
	static BOOL isTrace = false;
	static vector<pair<int, int>> points(20);

	switch (uMsg) {
	case WM_CREATE:
		hDC = GetDC(hWnd);
		break;

	case WM_PAINT:
		MoveToEx(hDC, points[0].first, points[0].second, NULL);
		for (int i = 1; i < points.size(); ++i) {
			LineTo(hDC, points[i].first, points[i].second);
		}
		break;

	case WM_LBUTTONDOWN:
		isTrace = true;
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		for (int i = 0; i < points.size(); ++i) {
			points[i].first = x;
			points[i].second = y;
		}
		InvalidateRect(hWnd, NULL, true);

		//MoveToEx(hDC, x, y, NULL);
		break;

	case WM_LBUTTONUP:
		isTrace = false;
		break;

	case WM_MOUSEMOVE:
		if (isTrace) {
			x = LOWORD(lParam);
			y = HIWORD(lParam);
			for (int i = 1; i < points.size(); ++i) {
				points[i - 1] = points[i];
			}
			points[points.size() - 1].first = x;
			points[points.size() - 1].second = y;
			InvalidateRect(hWnd, NULL, true);

			/*SelectObject(hDC, GetStockObject(BLACK_PEN));
			LineTo(hDC, x, y);
			SelectObject(hDC, GetStockObject(WHITE_PEN));
			MoveToEx(hDC, points[0].first, points[0].second, NULL);
			LineTo(hDC, points[1].first, points[1].second);*/
		}
		break;

	case WM_DESTROY:
		ReleaseDC(hWnd, hDC);
		PostQuitMessage(0); break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}