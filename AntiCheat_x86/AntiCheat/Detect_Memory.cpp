#include "MainH.h"

void MemoryScan(int addr , int originVal)
{
	BYTE val;
	while (true)
	{
		Sleep(100);
		ReadProcessMemory(GetCurrentProcess(), (LPVOID*)addr, &val, 1, NULL);
		if (originVal != val)
		{
			MessageBox(NULL, "메모리 변조감지", "HI", MB_OK);
		}
	}
}

void CheckMemory()
{
	MemoryScan((int)GetModuleHandleA("client.exe") + 0x1059, 17);
}

void MEM_Scan()
{
	CheckMemory();
}

void DetectMemory()
{
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(MEM_Scan), NULL, 0, 0);
}
