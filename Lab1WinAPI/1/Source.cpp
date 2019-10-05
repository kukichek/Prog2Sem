#include <windows.h>
#include <winuser.h> 
#include <stdio.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR par, int)
{
	char buff[9];
	sprintf_s(buff, " %s", par);
	MessageBox(NULL, buff, "Caption", MB_OKCANCEL);
	//системное диалоговое окно для вывода сообщений
	return 0;
}
