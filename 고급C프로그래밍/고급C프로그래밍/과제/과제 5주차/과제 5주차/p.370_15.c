#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void is_prime();

int main() 
{
	is_prime();

	return 0;
}

void is_prime()
{
	int cnt = 0;
	int i, j;
	for (i = 2; i < 100; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
				cnt++;
		}
		if (cnt == 0)
			printf("%d ", i);
		cnt = 0;
	}
}