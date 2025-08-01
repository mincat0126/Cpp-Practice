#include <stdio.h>

int main()
{
	const char* str1[] = { "¾È³ç" };
	const char* str2[] = { "¾È³ç" };

	if (str1 == str2)
	{
		printf("dd");
	}
}