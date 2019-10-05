#undef UNICODE
#include <windows.h>
#include <sstream>
#include"Wnd.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int a;
int b;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;

	Wind mainWnd("Sum", hInstance, nCmdShow, WndProc);

	std::stringstream in(lpCmdLine);
	in >> a;
	in >> b;

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
	TCHAR output[50];

	switch (message) {
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &clientRect);

		sprintf_s(output, "%d + %d = %d", a, b, a + b);
		DrawText(hDC, output, -1, &clientRect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

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