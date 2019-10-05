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
LPCSTR szTitle = "Создание окна Windows";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	/*хотя параметр hPrevInstance в Win32 всегда равно NULLпродолжаем проверять его значение */
	if (!hPrevInstance)
	{  /* инициализируем приложение -  подготавливаем данные класса окна и регистрируем его */
		if (!InitApplication(hInstance))
			return (FALSE);
	}
	/* завершаем создание копии приложения -     создаем главное окно приложения */
	if (!InitInstance(hInstance, nCmdShow))
		return (FALSE);

	/* Цикл обработки сообщений */
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
	// Заполняем структуру класса окна WNDCLASS
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
	// Регистрируем класс окна
	return RegisterClass(&wc);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hWnd = CreateWindow(
		szClassName,         // указатель на строку зарегистрированного имени класса
		szTitle,             // указатель на строку заголовка окна
		WS_OVERLAPPEDWINDOW, // стиль окна
		CW_USEDEFAULT,       // горизонтальная координата окна
		CW_USEDEFAULT,       // вертикальная координата окна
		CW_USEDEFAULT,       // ширина окна
		CW_USEDEFAULT,       // высота окна
		NULL,                // дескриптор родительского окна
		NULL,                // дескриптор меню окна
		hInstance,           // дескриптор экземпляра приложения
		NULL);               // указатель на дополнительные данные окна

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