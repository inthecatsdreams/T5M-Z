#include <Windows.h>
#include <iostream>
#include <string>

int main() {
	LPCUWSTR gameWindow = L"Call of Duty®: BlackOps";
	HWND hWnd = FindWindow(0, gameWindow);
	DWORD pId;
	if (hWnd == 0) {
		std::cout << "Cannot find window." << std::endl;
		system("pause");
		exit(-1);
	}
	GetWindowThreadProcessId(hWnd, &pId);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);


	LPVOID cash_address = (LPVOID)0x01C0A6C8;
	LPVOID health_address = (LPVOID)0x01A7987C;
	LPVOID first_gun_address = (LPVOID)0x01C08F00;
	LPVOID second_gun_address = (LPVOID)0x01C08F10;
	LPVOID fov_address = (LPVOID)0x02629378;
	LPVOID fps_addresss = (LPVOID)0x02628DC8;

	int cash = 999999;
	int health = 999;
	int second_gun_ammo = 999999;
	int first_gun_ammo = 999999;
	float fov = 120;
	int drawFPS = 3; //full mode



	DWORD first_gun_offset = sizeof(first_gun_ammo);
	DWORD second_gun_offset = sizeof(second_gun_ammo);
	DWORD health_offset = sizeof(health);
	DWORD cash_offset = sizeof(cash);
	DWORD fov_offset = sizeof(fov);
	DWORD fps_offset = sizeof(drawFPS);
	//std::cout << "Found process and attached to window" << std::endl;
	WriteProcessMemory(hProc, cash_address, &cash, cash_offset, NULL);
	WriteProcessMemory(hProc, fov_address, &fov, fov_offset, NULL);
	WriteProcessMemory(hProc, fps_addresss, &drawFPS, fps_offset, NULL);



	do {

		WriteProcessMemory(hProc, health_address, &health, health_offset, NULL);
		WriteProcessMemory(hProc, first_gun_address, &first_gun_ammo, first_gun_offset, NULL);
		WriteProcessMemory(hProc, second_gun_address, &second_gun_ammo, second_gun_offset, NULL);



	}while (hProc);


}

