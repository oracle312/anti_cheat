#include "MainH.h"

void BeingDebugged()
{
	if (IsDebuggerPresent())
		MessageBox(NULL, "����밨�� !! [BD]", "BD", MB_OK);
}

void CheckBD()
{
	BeingDebugged();
}

void BD_Scan()
{
	CheckBD();
}

void DetectBD()
{
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(BD_Scan), NULL, 0, 0);
}