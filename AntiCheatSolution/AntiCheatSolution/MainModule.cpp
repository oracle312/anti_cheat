#include "MainH.h"

#define _WIN32_WINNT 0X500


int AC_FindWindow()
{
	/*
	* Findwindow api�� �̿��� Ž�����
	* �ش� �����츦 ã���� ��� ������ �ڵ� ��ȯ, ã�� ���� ��� 0 ��ȯ
	*/
	if (ACS_FindWindow = true)
	{
		string str1 = "OLLYDBG";
		int ret;
		if (FindWindow(str1, 0))
			ret = true;
		return ret;

		/* �ζ��� ������� ����ؼ� ������ ���
		int ret;
		_asm
		{
			push 0 // ���ÿ� 0�� �ִ´�. [WindowName]
			lea eax, str1 // eax�� str1�� �ּҸ� �ִ´�.
			push eax // eax�� ���ÿ� �ִ´�. [ClassName]
			call dword ptr FindWindowA // call��ɾ ���� FindWindowA �Լ� ȣ��
			mov ret, eax // ret�� eax�� ���� �ִ´�.
		}
		return ret;
		*/
	}
}

