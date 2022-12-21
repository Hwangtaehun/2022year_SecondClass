#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i, j;
	for (i = 1; i <= 7; i++)
	{
		for (j = 1; j <= 7 - j; j++)
		{
			printf(" ");
		}
		for (j = 1; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}