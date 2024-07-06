#include "MainH.h"

DWORD __declspec(naked) GdaoceochgorhrocnvlbxdalfTTREQIO()
{
	__asm
	{

		push ecx
		mov eax, fs: [0x18]
		mov ecx, dword ptr[eax + 0x30]
		xor eax, eax
		mov al, byte ptr[ecx + 0x02]
		pop ecx
		retn
	}
}

void BeingDebugged()
{
	//if (IsDebuggerPresent())
	//	MessageBox(NULL, "µð¹ö±ë°¨Áö !! [BD]", "BD", MB_OK);
	if (GdaoceochgorhrocnvlbxdalfTTREQIO())
		MessageBox(NULL, "µð¹ö±ë°¨Áö !! [BD]", "BD", MB_OK);
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