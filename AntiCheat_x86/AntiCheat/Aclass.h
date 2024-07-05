class CONTENT
{
public:
	const char* ProtectEXE;

	int Splash_Activate;
	int Detect_NameWindow;
	int Detect_NameClass;
	int Detect_ProcID;
	int CRC_Main;
	int Detect_SBP;
	int Detect_HBP;
	int Detect_BD;
	int Detect_NtQSI;
	int Anti_ErasePE;
	int Detect_MEM;

	long CRC_MainEXE;

};
extern CONTENT anticheat;