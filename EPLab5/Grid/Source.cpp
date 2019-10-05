#undef UNICODE
#include <windows.h>
#include <sstream>
#include "Wnd.h"

using namespace std;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int m;
int n;

const int R = 10;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;

	Wind mainWnd("Grid", hInstance, nCmdShow, WndProc);

	stringstream in(lpCmdLine);
	in >> m;
	in >> n;

	if (n <= 0 || m <= 0) {
		MessageBox(NULL, "Wrond size", "Error", MB_OK);
	}

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;
	RECT clientRect;

	switch (message) {
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &clientRect);

		for (int i = 1; i < m; i++) {
			MoveToEx(hDC, 0, i * clientRect.bottom / m, nullptr);
			LineTo(hDC, clientRect.right, i * clientRect.bottom / m);
		}

		for (int i = 1; i < n; i++) {
			MoveToEx(hDC, i * clientRect.right / n, 0, nullptr);
			LineTo(hDC, i * clientRect.right / n, clientRect.bottom);
		}

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				SelectObject(hDC, CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
				Ellipse(hDC,
					j * clientRect.right / n - R, i * clientRect.bottom / m - R,
					j * clientRect.right / n + R, i * clientRect.bottom / m + R);
				DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
			}
		}

		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}