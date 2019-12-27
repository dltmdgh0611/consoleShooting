#include <iostream>
#include "shooting.h"
#include <Windows.h>
Player player = Player(0);

int main()
{
	int fx = 0;
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO consolecursor;
	consolecursor.bVisible = false;
	consolecursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &consolecursor);
	player.playerinit();



	while (true) {
		player.key_input();
		player.shooting(player.shootingcount, fx);
		player.shootingcount++;
		if (player.shootingcount > (player.bootflag ? 50 : 100)) {
			player.shootingcount = 0;
			fx = player.player_x;
		}
		Sleep(player.bootflag ? 10 : 20);


	}
}