#include "MainH.h"

bool WindowName(LPCSTR NameWindow)
{
	HWND WinName = FindWindowA(NULL, NameWindow);
	if ( WinName != NULL )
	{
		MessageBox(NULL, "디버거 감지 !! [FW]", "디버거 감지", MB_OK);
	}
	return true;
}

// 윈도우 이름 검색
void CheckWindow()
{
	WindowName("OllyDbg");
}

void FW_Scan()
{
	CheckWindow();
}

void DetectFW()
{
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(FW_Scan), NULL, 0, 0);
}
