#include "functions.h"
#include "windows.h"
#pragma comment(lib, "user32.lib")

NAN_METHOD(monitor) {
	int num = GetSystemMetrics(SM_CMONITORS);
	info.GetReturnValue().Set(num);
}

NAN_METHOD(lastinputtime) {
	LASTINPUTINFO lastInput;
	lastInput.cbSize = sizeof(LASTINPUTINFO);
	GetLastInputInfo(&lastInput);
	
	// calculate elapsed time (sec)
	int upTime = GetTickCount();
	int elapsedTime = (upTime - lastInput.dwTime) / 100;
	info.GetReturnValue().Set(elapsedTime);
}

NAN_METHOD(displaysleep) {
	SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);
}

NAN_METHOD(displaywake) {
	SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) -1);
}





