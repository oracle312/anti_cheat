#include "MainH.h"

void ClassName(LPCSTR NameClass)
{
	HWND WinClass = FindWindowExA(NULL, NULL, NameClass, NULL);
	if (WinClass != NULL)
	{
		MessageBox(NULL, "����� ����!! [CN]", "����Ű���", MB_OK);
	}

}

void CheckClass()
{
	ClassName("OllyDbg");
	ClassName("ProcessHacker");
	ClassName("PROCEXPLORER");
}

void CN_Scan()
{
	CheckClass();
}

void DetectCN()
{
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(CN_Scan), NULL, 0, 0);
}