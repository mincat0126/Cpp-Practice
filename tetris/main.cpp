#include "Turboc.h"

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define BX 5
#define BY 1
#define BW 10
#define BH 20

void DrawScreen();

struct Point
{
	int x, y;
};

Point Shape[][4][4] = {
     { {0,0,1,0,2,0,-1,0}, {0,0,0,1,0,-1,0,-2}, {0,0,1,0,2,0,-1,0}, {0,0,0,1,0,-1,0,-2} },
     { {0,0,1,0,0,1,1,1}, {0,0,1,0,0,1,1,1}, {0,0,1,0,0,1,1,1}, {0,0,1,0,0,1,1,1} },
     { {0,0,-1,0,0,-1,1,-1}, {0,0,0,1,-1,0,-1,-1}, {0,0,-1,0,0,-1,1,-1}, {0,0,0,1,-1,0,-1,-1} },
     { {0,0,-1,-1,0,-1,1,0}, {0,0,-1,0,-1,1,0,-1}, {0,0,-1,-1,0,-1,1,0}, {0,0,-1,0,-1,1,0,-1} },
     { {0,0,-1,0,1,0,-1,-1}, {0,0,0,-1,0,1,-1,1}, {0,0,-1,0,1,0,1,1}, {0,0,0,-1,0,1,1,-1} },
     { {0,0,1,0,-1,0,1,-1}, {0,0,0,1,0,-1,-1,-1}, {0,0,1,0,-1,0,-1,1}, {0,0,0,-1,0,1,1,1} },
     { {0,0,-1,0,1,0,0,1}, {0,0,0,-1,0,1,1,0}, {0,0,-1,0,1,0,0,-1}, {0,0,-1,0,0,-1,0,1} },
};

enum
{
    EMPTY, BRICK, WALL
};

const char* arTile[] = { ". ","■","□" };
int board[BW + 2][BH + 2];
int nx, ny;
int brick, rot;

void main()
{
    int nFrame, nStay;
    int x, y;

    setcursortype(NOCURSOR);
    randomize();
    clrscr();

    for (x = 0; x < BW + 2; x++)
    {
        for (y = 0; y < BH + 2; y++)
        {
            //블록 종류 정하기
            board[x][y] = (y == 0 || y == BH + 1 || x == 0 || x == BW + 1) ? WALL : EMPTY;
        }
    }
    DrawScreen();
}

void DrawScreen()
{
    int x, y;

    for (x = 0; x < BW + 2; x++)
    {
        for (y = 0; y < BH + 2; y++)
        {
            gotoxy(BX + x * 2, BY + y);
            //종류의 따라 블록 그리기
            puts(arTile[board[x][y]]);
        }
    }

    gotoxy(50, 3); puts("Tetris Ver 1.0");
    gotoxy(50, 5); puts("좌우:이동, 위:회전, 아래:내림");
    gotoxy(50, 6); puts("공백:전부 내림");
}