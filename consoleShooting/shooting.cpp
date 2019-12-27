#include "shooting.h"


Player::Player(char ch) : player_x(0), player_y(0) {
	key_value = ch;
}

void Player::playerinit() {

	move_player(60, key_X);
	move_player(50, key_Y);


}

void Player::draw() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			gotoxy(j + player_x, i + player_y);
			switch (player[i][j])
			{
			case 0: cout << "  "; break;
			case 1: cout << "<"; break;
			case 2: cout << "O"; break;
			case 3: cout << ">"; break;
			case 4: cout << "v"; break;
			}
		}
	}
}

void Player::clear() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			gotoxy(j + player_x, i + player_y);
			if (player[i][j] > 0) {
				cout << "  ";
			}
		}
	}
}

void Player::move_player(int move_value, bool xyflag) {
	clear();
	if (xyflag) player_x += move_value;
	else player_y += move_value;
	draw();
}

bool Player::key_input() {
	if (_kbhit()) {
		key = _getch();
		switch (key) {
		case UP: move_player(-1, key_Y); bootflag = false; break;
		case DOWN: move_player(1, key_Y); bootflag = false; break;
		case LEFT: move_player(-1, key_X); bootflag = false; break;
		case RIGHT: move_player(1, key_X); bootflag = false; break;
		case SPACE: bootflag = true;  break;
		}
		return true;
	}
	return false;
}

void Player::gotoxy(int x, int y) {
	COORD Cursor;
	Cursor.X = x;
	Cursor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cursor);
}

void Player::shooting(int i, int fx) {
	if (i < 45) {
		gotoxy(fx + 1, player_y - i - 4);
		cout << "o";
		gotoxy(fx + 1, player_y - i - 3);
		cout << " ";
		gotoxy(fx + 1, player_y - i - 2);
		cout << " ";
	}
	else {
		gotoxy(fx + 1, player_y - i - 3);
		cout << " ";
	}



}

Player::~Player() {}