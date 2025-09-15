#include <iostream>
#include <windows.h>
using namespace std;

const int WIDTH = 40;
const int HEIGHT = 20;

void gotoxy(int x, int y);
void HideCursor();


class Paddle
{
public: int x, y;
	  Paddle(int posX)
	  {
		  x = posX;
		  y = HEIGHT / 2 - 2; //Paddle ¸Ç À­ºÎºÐ
	  }
};

class Game
{
private :
	Paddle left, right;

public:
	Game() :left(2), right(WIDTH - 3)
	{

	}

	void DrawScreen()
	{
		gotoxy(0, 0);
		for(int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				if (j == 0 || j == WIDTH - 1) cout << "#";
				else if (j == left.x && i >= left.y && i < left.y + 4) cout << "|"; //left paddle
				else if (j == right.x && i >= right.y && i < right.y + 4) cout << "|";//right paddle
				else cout << " ";
			}
			cout << "\n";
		}
	}

	void Run()
	{
		while (true)
		{
			DrawScreen();
		}
	}
};

void main()
{
	HideCursor();
	Game g;
	g.Run();
}



void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void HideCursor()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}