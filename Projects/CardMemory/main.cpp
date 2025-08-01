#include  "Turboc.h"

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27

void InitGame();
void DrawScreen(BOOL bHint);

enum Status{HIDDEN, FLIP, TEMPFLIP};

struct tag_Cell
{
	int Num;
	Status St;
};

tag_Cell arCell[4][4];
int nx, ny;
int count = 0;

void main()
{
	int ch;
	int x, y;
	randomize();
	InitGame();

	for (;;)
	{
		gotoxy(nx * 5 + 2, ny * 3 + 2);

		ch = _getch();
		if (ch == 0xE0)
		{
			ch = _getch();
			switch (ch)
			{
			case LEFT:
				if (nx > 0)
					nx--;
				break;
			case RIGHT:
				if (nx < 3)
					nx++;
				break;
			case UP:
				if (ny > 0)
					ny--;
				break;
			case DOWN:
				if (ny < 3)
					ny++;
				break;
			}
		}
		else
		{
			switch (ch)
			{
			case ESC:
				exit(0);
				break;
			case ' ':
				break;
			}
		}
	}
}

void InitGame()
{
	int i, j;
	int x, y;

	nx, ny = 0;
	count = 0;

	memset(arCell, 0, sizeof(arCell));

	for (i = 0; i <= 8; i++)
	{
		for (j = 0; j < 2; j++)
		{
			do
			{
				x = random(4);
				y = random(4);
			} while (arCell[x][y].Num != 0);
			arCell[x][y].Num = i;
		}

		DrawScreen(TRUE);
		delay(2000);
		clrscr();
		DrawScreen(FALSE);
	}
}

void DrawScreen(BOOL bHint)
{
	int x, y;

	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			gotoxy(x * 5 + 2, y * 3 + 2);
			
			if (bHint == TRUE || arCell[x][y].St == FLIP)
			{
				gotoxy(wherex() - 1, wherey());
				printf("[%d]", arCell[x][y].Num);
			}
			else if (arCell[x][y].St == TEMPFLIP)
			{
				printf("%d", arCell[x][y].Num);
			}
			else
			{
				printf("?");
			}
		}
	}

}