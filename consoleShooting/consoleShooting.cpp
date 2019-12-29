#include "shooting.h"

Player player = Player(0);
void th1run();


int main()
{
	thread t1(th1run);
	int fx = 0;
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO consolecursor;
	consolecursor.bVisible = false;
	consolecursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &consolecursor);
	player.playerinit();

	while (true);
}

void th1run() {
	while (true) {
		player.key_input();
		player.shootingcount++;
		if (player.shootingcount > (player.bootflag ? 50 : 100)) {
			bullet* b = new bullet();
		}


	}
}


