#include "MainH.h"

typedef NTSTATUS(NTAPI* ntsit)(HANDLE, UINT, PVOID, ULONG);

void NtSetInformationThread()
{
	ntsit sit = (ntsit)GetProcAddress(GetModuleHandle("ntdll.dll"), "NtSetInformationThread");
	NTSTATUS stat = sit(GetCurrentProcess(), 0x11, 0, 0);
}

void CheckNtSIT()
{
	NtSetInformationThread();
}

void NtSIT_Scan()
{
	CheckNtSIT();
}

void DetectNtSIT()
{
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(NtSIT_Scan), NULL, 0, 0);
}