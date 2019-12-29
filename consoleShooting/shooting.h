#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <thread>
using namespace std;

#define UP 0x48
#define LEFT 0x4B
#define RIGHT 0x4D
#define DOWN 0x50
#define SPACE 0x20
#define key_X true
#define key_Y false

static int player_x, player_y;
void gotoxy(int x, int y);


class Player
{

	char key_value;
	int key;

public:
	int shootingcount = 0;
	
	bool bootflag;
	Player(char ch);
	~Player();
	int player[2][3]{
	{0,4,0},
	{1,2,3}
	};

	void playerinit();


	

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

class bullet
{
public:
	thread t2;
	void shooting(int x, int shot_y);
	void shootrun(int fplayer_x);
	bullet();
	~bullet();
private:

};

