#include <windows.h>

class Game
{
private :
public:

	void Draw()
	{

	}

	void Run()
	{
		while (true)
		{
			Draw();
		}
	}
};

void main()
{
	Game g;
	g.Run();
}
