#undef UNICODE
#include <windows.h>
#include <string>
#include "Wnd.h"

using namespace std;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;

	Wind mainWnd("Keyboard Input", hInstance, nCmdShow, WndProc);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HDC hDC;
	PAINTSTRUCT ps;
	TEXTMETRIC tm;

	static string text;

	static int charWidth, charHeight;
	static int clientWidth, clientHeight;
	static int nCharPerLine;
	static int nClientLines;
	static int lastLineAmount = 0, linesAmount = 0;

	int offset;
	int nLines;
	int nTailChar;

	switch (uMsg) {
	case WM_CREATE:
		hDC = GetDC(hWnd);
		SelectObject(hDC, GetStockObject(SYSTEM_FIXED_FONT));

		GetTextMetrics(hDC, &tm);
		charWidth = tm.tmAveCharWidth;
		charHeight = tm.tmHeight;

		ReleaseDC(hWnd, hDC);
		break;

	case WM_SIZE:
		clientWidth = LOWORD(lParam);
		clientHeight = HIWORD(lParam);

		nCharPerLine = max(1, clientWidth / charWidth);
		nClientLines = max(1, clientHeight / charHeight);

		if (hWnd == GetFocus())
			SetCaretPos(lastLineAmount * charWidth, linesAmount * charHeight);
		break;

	case WM_SETFOCUS:
		CreateCaret(hWnd, NULL, 0, charHeight);
		SetCaretPos(lastLineAmount * charWidth, linesAmount * charHeight);
		ShowCaret(hWnd);
		break;

	case WM_KILLFOCUS:
		HideCaret(hWnd);
		DestroyCaret();
		break;

	case WM_CHAR:
		switch (wParam) {
		case '\b':
			if (lastLineAmount <= 0) {
				if (linesAmount > 0) {
					lastLineAmount = nCharPerLine - 1;
					linesAmount--;
				}
			}
			else {
				lastLineAmount--;
			}

			offset = linesAmount * nCharPerLine + lastLineAmount;

			if (offset < text.size()) {
				text.erase(offset, 1);
				InvalidateRect(hWnd, NULL, TRUE);
			}
			break;

		default:
			text += (char)wParam;

			InvalidateRect(hWnd, NULL, TRUE);
			if (++lastLineAmount == nCharPerLine) {
				lastLineAmount = 0;
				if (++linesAmount == nClientLines) {
					MessageBox(hWnd, "No space for text", "Error", MB_OK);
					linesAmount--;
				}
			}
			break;
		}

		SetCaretPos(lastLineAmount * charWidth, linesAmount * charHeight);
		break;

	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		SelectObject(hDC, GetStockObject(SYSTEM_FIXED_FONT));

		if (text.size()) {
			nLines = text.size() / nCharPerLine;
			nTailChar = text.size() % nCharPerLine;

			int i;
			for (i = 0; i < nLines; ++i) {
				TextOut(hDC, 0, i * charHeight, text.c_str() + i * nCharPerLine, nCharPerLine);
			}
			TextOut(hDC, 0, i * charHeight, text.c_str() + i * nCharPerLine, nTailChar);
		}

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