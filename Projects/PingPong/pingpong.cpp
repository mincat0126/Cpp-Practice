#include <iostream>
#include <windows.h>
using namespace std;

const int WIDTH = 40;
const int HEIGHT = 20;

void gotoxy(int x, int y);
void HideCursor();



class Game
{
private :
public:

	void DrawScreen()
	{
		gotoxy(0, 0);
		for(int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				if (j == 0 || j == WIDTH - 1) cout << "#";
			}
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