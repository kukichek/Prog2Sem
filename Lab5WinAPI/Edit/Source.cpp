#undef UNICODE
#include <windows.h>
#include <string>

const int FONTHEIGHT = 20;
const int FONTWIDTH = 8;
const int DELTAFONTHEIGHT = 5;
const int DELTAFONTWIDTH = 2;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	HWND hWnd;
	WNDCLASSEX wc;

	char szClassName[] = "WndClass";
	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);


	if (!RegisterClassEx(&wc)) {
		char msg[100] = "Cannot register class: ";
		strcat_s(msg, szClassName);
		MessageBox(NULL, msg, "Error", MB_OK);
		return 0;
	}

	hWnd = CreateWindow(szClassName, "Window 1", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, (HMENU)NULL, hInstance, NULL);
	if (!hWnd) {
		char text[100] = "Cannot create window: ";
		strcat_s(text, "Window 1");
		MessageBox(NULL, text, "Error", MB_OK);
		return 0;
	}
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HDC hDC;
	PAINTSTRUCT ps;
	HFONT hFont;
	static LOGFONT lf;
	RECT clientRect;

	static std::string text = "Test";

	switch (uMsg) {
	case WM_CREATE:
		hDC = GetDC(hWnd);
		lf.lfHeight = FONTHEIGHT;
		lf.lfWidth = FONTWIDTH;
		hFont = CreateFontIndirect(&lf);
		ReleaseDC(hWnd, hDC);
		break;

	case WM_CHAR:
		GetClientRect(hWnd, &clientRect);
		switch (wParam) {
		case '+':
			if (lf.lfHeight < clientRect.bottom
				&& 1.5 * lf.lfWidth * text.size() < clientRect.right) {
				text += "+";
				lf.lfHeight += DELTAFONTHEIGHT;
				lf.lfWidth += DELTAFONTWIDTH;
			}
			else {
				MessageBox(hWnd, "Font is too large", "Error", MB_OK);
			}
			break;
		case '-':
			if (lf.lfHeight > DELTAFONTHEIGHT && lf.lfWidth > DELTAFONTWIDTH) {
				text += "-";
				lf.lfHeight -= DELTAFONTHEIGHT;
				lf.lfWidth -= DELTAFONTWIDTH;
			}
			else {
				MessageBox(hWnd, "Font is too small", "Error", MB_OK);
			}
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		hFont = CreateFontIndirect(&lf);
		GetClientRect(hWnd, &clientRect);
		SelectObject(hDC, hFont);
		if (text.size()) {
			DrawText(hDC, text.c_str(), -1, &clientRect, DT_CENTER | DT_VCENTER);
		}
		DeleteObject(SelectObject(hDC, GetStockObject(SYSTEM_FIXED_FONT)));
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}