#include "MainH.h"

void ErasePE()
{
	DWORD pe = 0;
	PCHAR base = (PCHAR)GetModuleHandle(NULL);

	VirtualProtect(base, 4096, PAGE_READWRITE, &pe);
	memset(base, 0, 4096);
}

void PEerase()
{
	ErasePE();
}

void PE_Erase()
{
	PEerase();
}

void AntiPE()
{
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(PE_Erase), NULL, 0, 0);
}