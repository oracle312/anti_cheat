#include "MainH.h"
CONTENT anticheat;

extern "C" __declspec(dllexport) void __cdecl Siyul() 
{
	// EXE Data
	anticheat.ProtectEXE = "테스트.exe";
	// Splash Image
	anticheat.Splash_Activate = 1;

	// anti FindWindow
	anticheat.Detect_NameWindow = 1; // 기능 ON OFF
	// anti ClassName
	anticheat.Detect_NameClass = 1;
	// anti ProcessID
	anticheat.Detect_ProcID = 1;
	// CRC Check
	anticheat.CRC_Main = 1;
	anticheat.CRC_MainEXE = 0x501fa266; //테스트 프로그램의 crc32 값
	// anti SoftWare BreakPoint - int 3
	anticheat.Detect_SBP = 0;
	// anti Hardware BreakPoint
	anticheat.Detect_HBP = 1;
	// anti BD
	anticheat.Detect_BD = 1;
	// anti NtQuerySystemInformation
	anticheat.Detect_NtQSI = 1;
	// anti Dump - Erase PE Header
	anticheat.Anti_ErasePE = 1;
	
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		Siyul();
		if (anticheat.Splash_Activate == 1)
		{
			SplashShow();
		}
		if (anticheat.Detect_NameWindow == 1)
		{
			DetectFW();
		}
		if (anticheat.Detect_NameClass == 1)
		{
			DetectCN();
		}
		if (anticheat.Detect_ProcID == 1)
		{
			DetectID();
		}
		if (anticheat.CRC_Main == 1)
		{
			_beginthread(MainCRC, 0, NULL);
		}
		if (anticheat.Detect_SBP == 1)
		{
			DetectSBP();
		}
		if (anticheat.Detect_HBP == 1)
		{
			DetectHBP();
		}
		if (anticheat.Detect_BD == 1)
		{
			DetectBD();
		}
		if (anticheat.Detect_NtQSI == 1)
		{
			DetectNtQSI();
		}
		if (anticheat.Anti_ErasePE == 1)
		{
			AntiPE();
		}
		MessageBoxA(0, "로드완료 !", "정보", MB_OK);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

