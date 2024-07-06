#include "MainH.h"

void SelfDebugging()
{
	DEBUG_EVENT d;
	STARTUPINFO s;
	PROCESS_INFORMATION p;

	ZeroMemory(&d, sizeof(DEBUG_EVENT));
	ZeroMemory(&s, sizeof(STARTUPINFO));
	ZeroMemory(&p, sizeof(PROCESS_INFORMATION));

	GetStartupInfo(&s);
	CreateProcess(NULL, GetCommandLine(), NULL, NULL, FALSE, DEBUG_PROCESS, NULL,
		NULL, &s, &p);
}

void DebugSelf()
{
	SelfDebugging();
}

void Debug_Self()
{
	Debug_Self();
}

void SelfDebug()
{
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(Debug_Self), NULL, 0, 0);
}