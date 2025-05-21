#include <stdio.h>
#include "Turboc.h"

int main()
{
	int i,j;
	
	printf("정수를 입력하세요 :");
	scanf_s("%d", &i);
	if (i%2 == 0)
	{
		printf("%d는 짝수입니다.", i);
	}
	else
	{
		printf("%d는 홀수입니다.", i);
	}

	delay(3000);
	clrscr();

	printf("첫 번째 정수를 입력하세요 :");
	scanf_s("%d", &i);
	printf("두 번째 정수를 입력하세요 :");
	scanf_s("%d", &j);

	if (i > j)
	{
		printf("%d가 %d보다 큽니다.\n", i, j);
	}
	else if (j > i)
	{
		printf("%d가 %d보다 작습니다.\n",i, j);
	}
	else
	{
		printf("%d와 %d는 같은 수입니다.\n",i, j);
	}
}