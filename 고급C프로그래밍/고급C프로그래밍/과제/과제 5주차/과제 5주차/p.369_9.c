#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void b_rand();

int main() 
{
	int cnt = 0;
	srand((unsigned)time(NULL));

	while (cnt < 5)
	{
		b_rand();
		cnt++;
	}

	return 0;
}

void b_rand()
{
	int num = 0;

	num = rand() % 2;

	printf("%d", num);
}