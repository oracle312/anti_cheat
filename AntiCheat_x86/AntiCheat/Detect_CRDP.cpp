#include "MainH.h"

void CheckRemoteDebugger()
{
	BOOL Debug;
	CheckRemoteDebuggerPresent(GetCurrentProcess(), &Debug);

	if (Debug)
		MessageBox(NULL, "디버거 감지 [CRDP]", "감지", MB_OK);
}



void CheckCRDP()
{
	CheckRemoteDebugger();
}

void CRDP_Scan()
{
	CheckCRDP();
}

void DetectCRDP()
{
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(CRDP_Scan), NULL, 0, 0);
}