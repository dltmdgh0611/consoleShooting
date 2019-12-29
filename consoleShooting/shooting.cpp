#include "shooting.h"


Player::Player(char ch)  {
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

void gotoxy(int x, int y) {
	COORD Cursor;
	Cursor.X = x;
	Cursor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cursor);
}


Player::~Player() {}


bullet::bullet() {
	
	int fplayer_x = player_x;
	t2([&](int fplayer_x) {
		for (int i = 0; i < 45; i++) {
			shooting(fplayer_x+1, i+1);
			
		}
	}, fplayer_x);
	gotoxy(player_x, player_y - 1);


}

void bullet::shooting(int x, int shot_y) {
	gotoxy(x, player_y - shot_y + 1);
	cout << " ";
	gotoxy(x, player_y - shot_y);
	cout << "o";
	if (shot_y == 44) {
		delete t2;
	}
}

