#include "MainH.h"

#define JUNK_CODE    	\
	__asm{push eax}		\
	__asm{xor eax, eax} \
	__asm{setpo al}		\
	__asm{push edx}		\
	__asm{xor edx, eax} \
	__asm{sal edx, 2}	\
	__asm{xchg eax, edx}\
	__asm{pop edx}		\
	__asm{or eax, ecx}  \
	__asm{pop eax}

CONTENT anticheat;

extern "C" __declspec(dllexport) void __cdecl Siyul()
{
	
	anticheat.ProtectEXE = "Client.exe";
	anticheat.Splash_Activate = 1;


	anticheat.Detect_NameWindow = 1;

	anticheat.Detect_NameClass = 1;
	anticheat.Detect_ProcID = 1;
	anticheat.CRC_Main = 1;
	anticheat.CRC_MainEXE = 0x38781371;
	anticheat.Detect_SBP = 1;
	anticheat.Detect_HBP = 1;
	anticheat.Detect_BD = 1;
	anticheat.Detect_NtQSI = 1;
	anticheat.Detect_MEM = 1;
	anticheat.Anti_ErasePE = 1;
	anticheat.Detect_CRDP = 1;
	anticheat.Self_Debugging = 0;
	anticheat.Set_NtSIT = 1;

}

BOOL APIENTRY DllMain(HMODULE hModule,
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
		if (anticheat.Detect_MEM == 1)
		{
			DetectMemory();
		}
		if (anticheat.Anti_ErasePE == 1)
		{
			AntiPE();
		}
		if (anticheat.Detect_CRDP == 1)
		{
			DetectCRDP();
		}
		if (anticheat.Self_Debugging == 1)
		{
			SelfDebug();
		}
		if (anticheat.Self_Debugging == 1)
		{
			DetectNtSIT();
		}
		MessageBoxA(0, "로드완료 !", "정보", MB_OK);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}