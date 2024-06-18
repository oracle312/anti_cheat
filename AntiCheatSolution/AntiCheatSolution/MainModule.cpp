#include "MainH.h"

#define _WIN32_WINNT 0X500


int AC_FindWindow()
{
	/*
	* Findwindow api를 이용한 탐지기법
	* 해당 윈도우를 찾았을 경우 윈도우 핸들 반환, 찾지 못할 경우 0 반환
	*/
	if (ACS_FindWindow = true)
	{
		string str1 = "OLLYDBG";
		int ret;
		if (FindWindow(str1, 0))
			ret = true;
		return ret;

		/* 인라인 어셈블리를 사용해서 구현한 모습
		int ret;
		_asm
		{
			push 0 // 스택에 0을 넣는다. [WindowName]
			lea eax, str1 // eax에 str1의 주소를 넣는다.
			push eax // eax를 스택에 넣는다. [ClassName]
			call dword ptr FindWindowA // call명령어를 통해 FindWindowA 함수 호출
			mov ret, eax // ret에 eax의 값을 넣는다.
		}
		return ret;
		*/
	}
}

