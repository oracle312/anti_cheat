#include "MainH.h"

CheckSum Check;
void CheckSum::DetectCRC()
{
	Check.CRCInit();
	if (anticheat.CRC_Main == 1)
	{
		long Crc1 = Check.FileCRC(anticheat.ProtectEXE);
		if (Crc1 != anticheat.CRC_MainEXE)
		{
			MessageBoxA(NULL, "���Ϻ������� !!", "����", MB_OK);
		}
	}
}

void MainCRC(void* lpParam)
{
	Check.DetectCRC();
}