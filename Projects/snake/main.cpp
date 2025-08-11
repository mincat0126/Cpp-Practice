#include "Turboc.h"

#define QS 1600
#define putchxy(x,y,ch) {gotoxy(x,y); putch;(ch);}

/*먹이 먹기
움직이기
길이 길어지기
사망판정
랜덤 음식
스테이지 선택
게임 정지*/

struct tag_Point
{
	int x, y;
};

tag_Point snake[QS];

int life;
int speed;
int stage;

void InitStage(int stage);

void main()
{
	int number;
	int ch;
	int x, y;

	life = 5;
	randomize();
	setcursortype(NOCURSOR);

	for (;;)
	{
		InitStage(stage);
	}
}

void InitStage(int stage)
{
	int i;
	clrscr();

	snake[0].x = 5; snake[0].y = 5;
	snake[1].x = 6; snake[1].y = 5;
	snake[2].x = 7; snake[2].y = 5;
	gotoxy(5, 5); puts("##S");

	for (i = 0; i < 80; i++)
	{
		putchxy(i, 0, 'M');
		putchxy(i, 22, 'M');
	}
	for (i = 0; i < 23; i++)
	{
		putchxy(0, i, 'M');
		putchxy(79, i, 'M');
	}

	switch (stage)
	{
	case 0:
	    speed = 150;
		for (i = 30; i <= 50; i++) { putchxy(i, 11, 'M'); }
		break;
	case 1:
		 speed = 100;
		for (i = 20; i <= 60; i++) { putchxy(i, 7, 'M'); putchxy(i, 14, 'M'); }
		break;
	case 2:
		 speed = 80;
		for (i = 20; i < 60; i++) { putchxy(i, 11, 'M'); }
		for (i = 6; i <= 16; i++) { putchxy(40, i, 'M'); }
		break;
	case 3:
		speed = 60;
		for (i = 20; i < 60; i++)
		{
			if (i < 30 || i > 50)
			{
				putchxy(i, 7, 'M');
				putchxy(i, 14, 'M');
			}
		}
		for (i = 7; i < 15; i++)
		{
			putchxy(20, i, 'M');
			putchxy(60, i, 'M');
		}
		break;
	case 4:
		speed = 50;
		break;
	}
}