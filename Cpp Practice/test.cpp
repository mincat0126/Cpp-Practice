#include <stdio.h>

int main()
{
	const char* str1[] = { "�ȳ�" };
	const char* str2[] = { "�ȳ�" };

	if (str1 == str2)
	{
		printf("dd");
	}
}