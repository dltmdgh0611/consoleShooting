#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

#define UP 0x48
#define LEFT 0x4B
#define RIGHT 0x4D
#define DOWN 0x50
#define SPACE 0x20
#define key_X true
#define key_Y false

class Player
{

	char key_value;
	int key;

public:
	int shootingcount = 0;
	int player_x, player_y;
	bool bootflag;
	Player(char ch);
	~Player();
	int player[2][3]{
	{0,4,0},
	{1,2,3}
	};

	void playerinit();

	void shooting(int i, int fx);

	void gotoxy(int x, int y);

	bool key_input();

	void draw();

	void clear();

	void move_player(int move_value, bool xyflag);

private:
};


class Monster1
{
public:
	int monster1[3][3]{
	{1,0,1},
	{1,1,1},
	{0,1,0}
	};
	Monster1();
	~Monster1();

private:

};