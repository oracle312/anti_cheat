#include "MainH.h"

void SoftwareBreakPoint()
{
	/*int flag = 0;
	__try
	{
		__asm
		{
			int 3;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		flag = 1;
	}
	if (flag == 0)
		MessageBox(NULL, "����� ���� !! [int3]", "SBP", MB_OK);*/
}

void SoftwareBreakPoint2()
{
	/*int flag = 0;
	__try
	{
		__asm
		{
			int 0x41
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		flag = 1;
	}
	if (flag ==0)
		MessageBox(NULL, "����� ���� !! [int41]", "SBP", MB_OK);*/
}

// ������ �̸� �˻�
void CheckSBP()
{
	SoftwareBreakPoint();
	SoftwareBreakPoint2();
}

void SBP_Scan()
{
	CheckSBP();
}

void DetectSBP()
{
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(SBP_Scan), NULL, 0, 0);
}