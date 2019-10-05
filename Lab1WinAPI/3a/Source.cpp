#undef UNICODE
#include <windows.h>
#include"FigureDrawer.h"
#include"RectangleDrawer.h"
#include"EllipseDrawer.h"
#include"PieDrawer.h"
#include"RombusDrawer.h"

struct RGBColor {
	int r, g, b;
	RGBColor() {
		r = rand() % 255;
		g = rand() % 255;
		b = rand() % 255;
	}
};

class ChangeColor {
	HDC *hDC;
public:
	ChangeColor(HDC *_HDC) :hDC(_HDC) {}
	void operator() (RGBColor penColor, RGBColor brushColor) {
		SelectObject(*hDC, GetStockObject(DC_BRUSH));
		SetDCBrushColor(*hDC, RGB(brushColor.r, brushColor.g, brushColor.b));
		HPEN hPen = CreatePen(rand() % 6, 1, RGB(penColor.r, penColor.g, penColor.b));
		SelectObject(*hDC, hPen);
	}
};

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "WinAPI";
LPCSTR szTitle = "�������� ���� Windows";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	/*���� �������� hPrevInstance � Win32 ������ ����� NULL���������� ��������� ��� �������� */
	if (!hPrevInstance)
	{  /* �������������� ���������� -  �������������� ������ ������ ���� � ������������ ��� */
		if (!InitApplication(hInstance))
			return (FALSE);
	}
	/* ��������� �������� ����� ���������� -     ������� ������� ���� ���������� */
	if (!InitInstance(hInstance, nCmdShow))
		return (FALSE);

	/* ���� ��������� ��������� */
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (msg.wParam);
}

BOOL InitApplication(HINSTANCE hInstance)
{
	WNDCLASS  wc;
	// ��������� ��������� ������ ���� WNDCLASS
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	wc.hCursor = LoadCursor(NULL, IDC_IBEAM);
	wc.hbrBackground = (HBRUSH)(COLOR_APPWORKSPACE - 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;
	// ������������ ����� ����
	return RegisterClass(&wc);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hWnd = CreateWindow(
		szClassName,         // ��������� �� ������ ������������������� ����� ������
		szTitle,             // ��������� �� ������ ��������� ����
		WS_OVERLAPPEDWINDOW, // ����� ����
		CW_USEDEFAULT,       // �������������� ���������� ����
		CW_USEDEFAULT,       // ������������ ���������� ����
		CW_USEDEFAULT,       // ������ ����
		CW_USEDEFAULT,       // ������ ����
		NULL,                // ���������� ������������� ����
		NULL,                // ���������� ���� ����
		hInstance,           // ���������� ���������� ����������
		NULL);               // ��������� �� �������������� ������ ����

	if (!hWnd)    return (FALSE);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return (TRUE);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;
	RECT rect;
	RECT figureReg;
	const int TEXTHEIGHT = 15;
	HBRUSH brush;
	HPEN pen;
	EllipseDrawer ellipseDraw;
	RectangeDrawer rectDraw;
	PieDrawer pieDraw;
	RombusDrawer rombDraw;
	ChangeColor drawer(&hDC);

	switch (message)
	{
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		/*SelectObject(hDC, brush);
		SelectObject(hDC, pen);*/

		figureReg.left = rect.left;			figureReg.top = rect.top;
		figureReg.right = rect.right / 2;	figureReg.bottom = rect.bottom / 2 - TEXTHEIGHT;
		drawer(RGBColor(), RGBColor());
		ellipseDraw.redraw(hDC, figureReg);

		figureReg.left = rect.right / 2;
		figureReg.right = rect.right;
		drawer(RGBColor(), RGBColor());
		rectDraw.redraw(hDC, figureReg);

		figureReg.left = rect.left;			figureReg.top = rect.bottom / 2;
		figureReg.right = rect.right / 2;	figureReg.bottom = rect.bottom - TEXTHEIGHT;
		drawer(RGBColor(), RGBColor());
		pieDraw.redraw(hDC, figureReg);

		figureReg.left = rect.right / 2;	
		figureReg.right = rect.right;		
		drawer(RGBColor(), RGBColor());
		rombDraw.redraw(hDC, figureReg);

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