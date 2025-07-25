#include "Turboc.h"

#define ESC 27
#define MAXENEMY 10
#define MAXBALL 20

int fx;
int bx, by;
int Score;

struct tag_Enemy
{
    BOOL exist;
    int Type;
    int x, y;
    int Delta;
    int nFrame;
    int nStay;
} Enemy[MAXENEMY];

struct tag_Ball
{
    BOOL exist;
    int x, y;
    int nFrame;
    int nStay;
} Ball[MAXBALL];

char* arEnemy[] = { " ;:^:; "," zZWZz ", " oO@Oo ", " <-=-> " };

BOOL IsKeyDown(int Key)
{
    return ((GetAsyncKeyState(Key) & 0x8000) != 0);
}

void main()
{
    int ch;
    int i, j;
    BOOL bFound;
    int count;

    randomize();
    clrscr();
    setcursortype(NOCURSOR);
    fx = 40;
    bx = -1;
    Score = 0;

    for (count = 0;; count++)
    {

        //ÁÂ¿ìÀÌµ¿
        if (count % 5 == 0)
        {
            if (IsKeyDown(VK_LEFT))
                if (fx > 6)
                    fx--;
            if (IsKeyDown(VK_RIGHT))
                if (fx < 72)
                    fx++;
        }

        //ÃÑ¾Ë½î±â ¶Ç´Â ESC
        if (_kbhit())
        {
            ch = _getch();
            if (ch == 0xE0 || ch == 0)
                _getch();
            else
            {
                switch (ch)
                {
                case' ':
                    if (bx == -1)
                    {
                        bx = fx;
                        by = 23;
                    }
                    break;
                case ESC:
                    goto end;
                }
            }
        }

        //Àû »ý¼º
        if (random(100) == 0)
        {
            for (i = 0; i < MAXENEMY && Enemy[i].exist == TRUE; i++) { ; }
            if (i != MAXENEMY)
            {
                if (random(2) == 1)
                {
                    Enemy[i].x = 5;
                    Enemy[i].Delta = 1;
                }
                else
                {
                    Enemy[i].x = 75;
                    Enemy[i].Delta = -1;
                }

                for (;;)
                {
                    Enemy[i].y = random(10) + 1;
                    for (bFound = FALSE, j = 0; j < MAXENEMY; j++)
                    {
                        if (Enemy[i].exist == TRUE && Enemy[i].y == Enemy[i].y)
                        {
                            bFound = TRUE;
                            break;
                        }
                    }
                    Enemy[i].nFrame = Enemy[i].nStay = random(6) + 1;
                    Enemy[i].Type = random(sizeof(arEnemy)/sizeof(arEnemy[i]));
                    Enemy[i].exist = TRUE;
                }
            }
        }

        //¾Æ±º ÃÑ¾Ë ÀÌµ¿
        if (bx != -1)
        {
            gotoxy(bx, by);
            putch(' ');

            if (by == 0)
                bx = -1;
            else
            {
                by--;
                goyoxy(bx, by);
                putch('i');
            }
        }
    }
}