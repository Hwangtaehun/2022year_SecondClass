#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int cnt = 0;
	int i = 4;
	int j;
	for (i = 2; i <= 100; i++)
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
	return 0;
}