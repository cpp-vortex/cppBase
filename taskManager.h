#pragma once

#include <windows.h>
#include <tlhelp32.h>
#include <string>
#include <iostream>

void task() {
	HANDLE hS = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hS == INVALID_HANDLE_VALUE) {
		return;
	}
	PROCESSENTRY32W ta;
	ta.dwSize = sizeof(PROCESSENTRY32W);

	if (Process32FirstW(hS, &ta)) {
		do {
			std::wcout << L"ID " << ta.th32ProcessID << L" Name " << ta.szExeFile << L"\n";

		} while (Process32NextW(hS, &ta));
	}
}
