#pragma once
#include <windows.h>
#include <string>
#include <format>

void regeAdd() {

	wchar_t Path[260];
	GetModuleFileNameW(NULL, Path, 260);

	HKEY hRunKey;
	RegOpenKeyExW(
		HKEY_CURRENT_USER,
		L"Software\\Microsoft\\Windows\\CurrentVersion\\Run",
		0,
		KEY_SET_VALUE,
		&hRunKey
	);

	RegSetValueExW(
		hRunKey,
		L"Scanner",
		0,
		REG_SZ,
		(BYTE*)Path,
		(lstrlenW(Path) + 1) * sizeof(wchar_t)
	);

}

