#include "MainH.h"

void HardwareBreakPoint()
{
	int flag = 0;
	CONTEXT my;

	ZeroMemory(&my, sizeof(CONTEXT));
	my.ContextFlags = CONTEXT_DEBUG_REGISTERS;

	if (GetThreadContext(GetCurrentThread(), &my) != 0)
	{
		if (my.Dr0 != 0)
			++flag;
		if (my.Dr1 != 0)
			++flag;
		if (my.Dr2 != 0)
			++flag;
		if (my.Dr3 != 0)
			++flag;
	}

	if (flag != 0)
		MessageBox(NULL, "µð¹ö±ë°¨Áö !! [HBP]", "HBP", MB_OK);
}

void CheckHBP()
{
	HardwareBreakPoint();
}

void HBP_Scan()
{
	CheckHBP();
}

void DetectHBP()
{
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(HBP_Scan), NULL, 0, 0);
}