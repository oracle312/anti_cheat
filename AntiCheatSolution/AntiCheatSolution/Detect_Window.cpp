#include "MainH.h"

bool WindowName(LPCSTR NameWindow)
{
	HWND WinName = FindWindowA(NULL, NameWindow);
	if ( WinName != NULL )
	{
		MessageBox(NULL, "����� ���� !! [FW]", "����� ����", MB_OK);
	}
	return true;
}

// ������ �̸� �˻�
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
