#include "Turboc.h"

/*���� �Ա�
�����̱�
���� �������
�������
���� ����
�������� ����
���� ����*/

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