#undef UNICODE
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>	
#include <windowsx.h>
#include <vector>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <winuser.h>

using namespace std;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL InitApplication(HINSTANCE hInstance);

LPCSTR szClassName = "MainWindowClassName";
LPCSTR szTitle = "Clocks";

const int CLOCKRADIUS = 100;

HACCEL CreateAccelerators()
{
	ACCEL acc[1];
	acc[0].cmd = 1001;
	acc[0].fVirt = FVIRTKEY | FCONTROL;
	acc[0].key = 0x53;

	return CreateAcceleratorTable((LPACCEL)acc, 1);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR, int nCmd)
{
	MSG msg;
	HWND hwnd;
	srand(time(NULL));
	if (!hPrevInstance)
		if (!InitApplication(hInstance))
			return (FALSE);

	hwnd = CreateWindow(
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

	if (!hwnd) return (FALSE);
	ShowWindow(hwnd, nCmd);
	UpdateWindow(hwnd);

	HACCEL hAccel = CreateAccelerators();

	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!(hAccel && TranslateAccelerator(hwnd, hAccel, &msg)))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	};

	return (msg.wParam);
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rect;
	GetClientRect(hwnd, &rect);
	static int time;
	static bool isTimerExist;
	char timeStr[10];

	HFONT font = CreateFontA(25, 20, 0, 0, 400, 3, 4, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, ("Arial"));

	switch (msg)
	{
	case WM_CREATE: 
		time = 0;
		SetTimer(hwnd, 1, 1000, NULL);
		isTimerExist = 1;
		InvalidateRect(hwnd, 0, TRUE);
		break;
	case WM_TIMER:
		time++;
		InvalidateRect(hwnd, 0, TRUE);
		break;
	case WM_SIZE: 
		InvalidateRect(hwnd, 0, TRUE);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		SetTextAlign(hdc, TA_CENTER);
		SetBkColor(hdc, RGB(173, 175, 240));

		SelectObject(hdc, GetStockObject(NULL_PEN));
		SelectObject(hdc, CreateSolidBrush(RGB(173, 175, 240)));
		Ellipse(hdc, rect.right / 2 - CLOCKRADIUS, rect.bottom / 2 - CLOCKRADIUS, rect.right / 2 + CLOCKRADIUS, rect.bottom / 2 + CLOCKRADIUS);

		_itoa_s(time, timeStr, 4, 10);
		TextOut(hdc, rect.right / 2, rect.bottom / 2 - 10, LPSTR(timeStr), strlen(timeStr));

		EndPaint(hwnd, &ps);
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == 1001) {
			time = 0;
			if (!isTimerExist) {
				SetTimer(hwnd, 1, 1000, NULL);
				isTimerExist = 1;
			} else{
				KillTimer(hwnd, 1);
				SetTimer(hwnd, 1, 1000, NULL);
			}
			InvalidateRect(hwnd, 0, TRUE);
		}
		break;
	case  WM_CHAR:
		if (wParam == '+') {
			if (!isTimerExist) {
				SetTimer(hwnd, 1, 1000, NULL);
				isTimerExist = 1;
			}
		}
		else {
			if (wParam == '-') {
				if (isTimerExist) {
					KillTimer(hwnd, 1);
					isTimerExist = 0;
				}
			}
		}
		break;
	case WM_DESTROY:
		KillTimer(hwnd, 1);
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