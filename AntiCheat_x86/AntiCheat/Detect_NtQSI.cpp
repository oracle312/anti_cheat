#include "MainH.h"

typedef struct _SYSTEM_KERNEL_DEBUGGER_INFORMATION
{
	BOOLEAN KdDebuggerEnabled;
	BOOLEAN KdDebuggerNotPresent;
} SYSTEM_KERNEL_DEBUGGER_INFORMATION;

typedef NTSTATUS(WINAPI* ntqsi)(ULONG, PVOID, ULONG, PULONG);

void NtQuerySystem()
{
	SYSTEM_KERNEL_DEBUGGER_INFORMATION sk;
	ntqsi qsi = (ntqsi)GetProcAddress(GetModuleHandle("ntdll.dll"), "NtQuerySystemInformation");
	qsi(0x23, &sk, 2, NULL);
	if (sk.KdDebuggerEnabled && !sk.KdDebuggerNotPresent)
		MessageBox(NULL, "µð¹ö±ë°¨Áö !!", "NtQSI", MB_OK);
}

void CheckNtQSI()
{
	NtQuerySystem();
}

void NtQSI_Scan()
{
	CheckNtQSI();
}

void DetectNtQSI()
{
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(NtQSI_Scan), NULL, 0, 0);
}