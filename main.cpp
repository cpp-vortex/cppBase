#include <iostream>
#include <windows.h>
#include <string>
#include <tlhelp32.h>
#include <format>
#include "regAdd.h"
#include "ProcessT.h"
#include "taskManager.h"

using namespace std;

void chechWinRun() {
	HKEY hKey;
	RegOpenKeyExW(
		HKEY_LOCAL_MACHINE,
		L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
		0,
		KEY_QUERY_VALUE,
		&hKey
	);

	wchar_t shellByfer[260];
	DWORD shellSize = sizeof(shellByfer);

	RegQueryValueExW(
		hKey,
		L"Shell",
		NULL,
		NULL,
		(LPBYTE)shellByfer,
		&shellSize
	);

	wchar_t UserinitByfer[260];
	DWORD UserinitSize = sizeof(UserinitByfer);

	RegQueryValueExW(
		hKey,
		L"Userinit",
		NULL,
		NULL,
		(LPBYTE)UserinitByfer,
		&UserinitSize
	);
	
	RegCloseKey(hKey);
	std::wstring report = std::format(L"Shell: {},\n Userinit: {}\n", shellByfer, UserinitByfer);
	MessageBoxW(NULL, report.c_str(), L"Result", MB_OK | MB_ICONINFORMATION);
}

void screenshoot() {
	int weight = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);

	HDC hScreen = GetDC(NULL);
	HDC hMemory = CreateCompatibleDC(hScreen);
	HBITMAP hMap = CreateCompatibleBitmap(hScreen, weight, height);
	SelectObject(hMemory, hMap);

}

void qasd() {
	RegisterHotKey(
		NULL,
		1,
		MOD_CONTROL | MOD_SHIFT,
		0x58
	);

	MSG aqqw;
	while (GetMessage(&aqqw, NULL, 0, 0)) {
		if (aqqw.message == WM_HOTKEY) {
			if (aqqw.wParam == 1) {
				chechWinRun();
				regeAdd();
				task();
				break;
			}
		}
	}
}

int main() {
	HWND hConsole = GetConsoleWindow();
	ShowWindow(hConsole, SW_HIDE);
	setlocale(LC_ALL, "Russian");
	qasd();
	std::wstring target;
	wcout << L"Target?\n";
	wcin >> target;
	processT(target);

    return 0;
}

