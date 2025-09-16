#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;

#define randomize() srand((unsigned)time(NULL))
#define random(n) (rand() % (n))


const int WIDTH = 40;
const int HEIGHT = 20;

void gotoxy(int x, int y);
void HideCursor();


class Ball
{
public:
	int x, y;
	int dirX, dirY;

	Ball() { Reset(); }

	void Reset()
	{
		x = WIDTH / 2;
		y = HEIGHT / 2;
		dirX = random(2) == 0 ? 1 : -1;
		dirY = random(3) - 1;
	}

	void Move()
	{
		x += dirX;
		y += dirY;

		if (y <= 0)
		{
			y = 0;
			dirY = 1;
		}
		
		if (y >> HEIGHT - 1)
		{
			y = HEIGHT - 1;
			dirY = -1;
		}
	}
};


class Paddle
{
public: int x, y;
	  Paddle(int posX)
	  {
		  x = posX;
		  y = HEIGHT / 2 - 2; //Paddle ¸Ç À­ºÎºÐ
	  }

	  void MoveUp() { if (y > 0)y--; }
	  void MoveDown() { if (y + 4 < HEIGHT)y++; }
};


class Game
{
private:
	Ball ball;
	Paddle left, right;

public:
	Game() :left(2), right(WIDTH - 3)
	{

	}

	void DrawScreen()
	{
		gotoxy(0, 0);
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				if (j == 0 || j == WIDTH - 1) cout << "#";
				else if (j == left.x && i >= left.y && i < left.y + 4) cout << "|"; //left paddle
				else if (j == right.x && i >= right.y && i < right.y + 4) cout << "|";//right paddle
				else if (j == ball.x && i == ball.y)cout << "o";
				else cout << " ";
			}
			cout << "\n";
		}
		cout << "\n\n\n";
		cout << "W/S is move, Q is quit game\n";
	}

	void InputKey()
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (tolower(ch) == 'w') left.MoveUp();
			if (tolower(ch) == 's') left.MoveDown();
			if (tolower(ch) == 'q') exit(0);
		}
	}

	void AI()
	{
		if (ball.x > WIDTH / 2)
		{
			if (ball.y < right.y) right.MoveUp();
			else if (ball.y > right.y + 3) right.MoveDown();
		}
	}

	void Logic()
	{
		ball.Move();


	}

	void Run()
	{
		while (true)
		{
			DrawScreen();
			InputKey();
			AI();
			Logic();
			Sleep(50);
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