#include "MainH.h"

void GetProcess(const char* ProcName)
{
	PROCESSENTRY32 pe32; //tlhelp32
	HANDLE hSnapshot = NULL;

	pe32.dwSize = sizeof(PROCESSENTRY32);
	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (Process32First(hSnapshot, &pe32))
	{
		do
		{
			if (strcmp(pe32.szExeFile, ProcName) == 0)
			{
				MessageBoxA(NULL, "디버거 감지!! [PID]", "디버거감지", MB_OK);
			}
		} while (Process32Next(hSnapshot, &pe32));
	}
}

void CheckProcess()
{
	GetProcess("ollydbg.exe");
	GetProcess("ProcessHacker.exe");
	GetProcess("procexp64.exe");
}

void ID_Scan()
{
	CheckProcess();
}

void DetectID()
{
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(ID_Scan), NULL, 0, 0);
}