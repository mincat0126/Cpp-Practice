#include <stdio.h>
#include "Turboc.h"

int main()
{
	int i,j;
	
	printf("������ �Է��ϼ��� :");
	scanf_s("%d", &i);
	if (i%2 == 0)
	{
		printf("%d�� ¦���Դϴ�.", i);
	}
	else
	{
		printf("%d�� Ȧ���Դϴ�.", i);
	}

	delay(3000);
	clrscr();

	printf("ù ��° ������ �Է��ϼ��� :");
	scanf_s("%d", &i);
	printf("�� ��° ������ �Է��ϼ��� :");
	scanf_s("%d", &j);

	if (i > j)
	{
		printf("%d�� %d���� Ů�ϴ�.\n", i, j);
	}
	else if (j > i)
	{
		printf("%d�� %d���� �۽��ϴ�.\n",i, j);
	}
	else
	{
		printf("%d�� %d�� ���� ���Դϴ�.\n",i, j);
	}
}