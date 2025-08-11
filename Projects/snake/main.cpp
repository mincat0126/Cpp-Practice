#include "Turboc.h"

/*먹이 먹기
움직이기
길이 길어지기
사망판정
랜덤 음식
스테이지 선택
게임 정지*/

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
}