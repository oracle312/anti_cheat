#include "Splash.h"


void SplashShow() {
	CSplash splash1(TEXT("AntiCheat.bmp"), RGB(128, 128, 128));
	splash1.ShowSplash();
	Sleep(2000);
	splash1.CloseSplash();
}