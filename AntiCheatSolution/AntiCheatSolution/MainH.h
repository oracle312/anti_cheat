#include <windows.h>
#include <string>
#include <stdio.h>
#include <TlHelp32.h>
#include <process.h>
#include "Aclass.h"
#include "Bclass.h"
#include "CRC.h"

#pragma warning (disable: 4996)

using namespace std;

extern  "C"  __declspec(dllexport) void __cdecl Siyul();