#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_prime(int n);

int main()
{
	int n, i;
	printf("정수를 입력하세요: ");
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++)
	{
		if (is_prime(i) == 1)
			printf("%d ", i);
	}

	return 0;
}

int is_prime(int n)
{
	int i;
	if (n == 1)
	{
		return 0;
	}
	else
	{
		for (i = 2; i < n; i++)
		{
			if (n % i == 0)
				return 0;
		}
		return 1;
	}
}