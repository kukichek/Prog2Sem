#undef UNICODE
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>	//
#include <windowsx.h>
#include <vector>
#include <ctime>
#include <iostream>

using namespace std;

const int INITRADIUS = 30, DELTARADIUS = 15;

struct Circle
{
	POINT center;
	int radius;
	Circle(POINT in_lpp) : radius(INITRADIUS), center(in_lpp) {};
};

vector<Circle> circles;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "MainWindowClassName";
LPCSTR szTitle = "MainWindowTitle";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR, int nCmd)
{
	MSG msg;
	srand(time(NULL));
	if (!hPrevInstance)
		if (!InitApplication(hInstance))
			return (FALSE);

	if (!InitInstance(hInstance, nCmd))
		return (FALSE);


	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	};

	return (msg.wParam);
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rect, rect1;
	GetWindowRect(hwnd, &rect);
	GetClientRect(hwnd, &rect1);

	POINT cursor_buf;

	switch (msg)
	{
	case WM_SIZE:
		InvalidateRect(hwnd, 0, TRUE);
		break;

	case WM_PAINT:
	{
		hdc = BeginPaint(hwnd, &ps);

		for (auto i: circles) {
			Ellipse(hdc, i.center.x - i.radius, i.center.y - i.radius, i.center.x + i.radius, i.center.y + i.radius);
		}

		EndPaint(hwnd, &ps);
		break;
	}

	case WM_LBUTTONDOWN:
	{
		if (GetCursorPos(&cursor_buf)) {
			bool c_found = false;
			cursor_buf.x -= (rect.right - rect1.right - 4);
			cursor_buf.y -= (rect.bottom - rect1.bottom - 4);

			for (auto it = circles.rbegin(); it != circles.rend(); ++it) {
				int x = it->center.x - cursor_buf.x;
				int y = it->center.y - cursor_buf.y;
				int r = it->radius;
				if (x * x + y * y <= r * r) {
					it->radius += DELTARADIUS;
					c_found = true;
					break;
				}
			}

			if (!c_found) {
				circles.push_back(Circle(cursor_buf));
			}

			InvalidateRect(hwnd, 0, TRUE);
		}
		break;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

BOOL InitApplication(HINSTANCE hInstance)
{
	WNDCLASS wc;


	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = GetStockBrush(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;

	return RegisterClass(&wc);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmd)
{
	HWND hWnd;
	hWnd = CreateWindow(
		szClassName,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
	if (!hWnd) return (FALSE);
	ShowWindow(hWnd, nCmd);
	UpdateWindow(hWnd);
	return (TRUE);
}