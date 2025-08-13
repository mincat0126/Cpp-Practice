#include "Turboc.h"

#define QS 1600
#define putchxy(x,y,ch) {gotoxy(x,y); _putch;(ch);}

int getchon(int x, int y);
void InitStage(int stage);
BOOL MoveSnake();

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

int maxFood;
int life;
int speed;
int stage;

void main()
{
	int eatFood;
	int ch;
	int x, y;

	life = 5;
	randomize();
	setcursortype(NOCURSOR);

	for (;;)
	{
		InitStage(stage);
		gotoxy(0, 23); printf("스테이지 : %d", stage + 1);
		gotoxy(20, 23); printf("남은 기회 : %d", life);

		for (eatFood=0;eatFood<maxFood;eatFood++)
		{
			gotoxy(40, 23); printf("남은 먹이 : %d ", maxFood - eatFood);
			gotoxy(60, 23); printf("꼬리 길이 : 2 ");
			do
			{
				x = random(80);
				y = random(22);
			} while (getchon(x,y)!=' ');

			gotoxy(x, y);
			printf("%d", random(9) + 1);
		}

		if (eatFood == 0)
		{
			ch = _getch();
			if (ch == 0xE0)
				_getch();
			else
			{
				if (ch == 27)
				{
					setcursortype(NORMALCURSOR);
					exit(0);
				}
				if (tolower(ch) == 'n')
				{
					stage = (stage == 4 ? 0 : stage++);
					break;
				}
				if (tolower(ch) == 'p')
				{
					stage = (stage == 0 ? 4 : stage--);
				}
			}
		}

		if (MoveSnake() == TRUE)
		{
		}

		if (eatFood == maxFood)
		{
			gotoxy(12, 20);
			puts("축하합니다. 아무 키나 누르시면 다음 스테이지로 갑니다.");
			delay(2000);
			stage++;
		}
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
		maxFood = 5; speed = 150;
		for (i = 30; i <= 50; i++) { putchxy(i, 11, 'M'); }
		break;
	case 1:
		maxFood = 10; speed = 100;
		for (i = 20; i <= 60; i++) { putchxy(i, 7, 'M'); putchxy(i, 14, 'M'); }
		break;
	case 2:
		maxFood = 15; speed = 80;
		for (i = 20; i < 60; i++) { putchxy(i, 11, 'M'); }
		for (i = 6; i <= 16; i++) { putchxy(40, i, 'M'); }
		break;
	case 3:
		maxFood = 20; speed = 60;
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
		maxFood = 1970; speed = 50;
		break;
	}
}

BOOL MoveSnake()
{
	for (;;)
	{

	}
}

//x,y 위치의 문자 조사
int getchon(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	TCHAR Char;
	DWORD dwRead;

	ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE),
							   &Char, 1, Cur, &dwRead);
	return Char;
}