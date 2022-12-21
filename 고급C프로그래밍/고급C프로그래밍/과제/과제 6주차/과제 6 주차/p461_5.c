#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void Compare(int a[]);

int main()
{
	int result = 0;
	int cnt[10] = { 0 };
	srand((unsigned)time(NULL));

	for (int i = 0; i < 100; i++)
	{
		result = rand() % 10;
		cnt[result] += 1;
	}

	Compare(cnt);

	return 0;
}

void Compare(int a[])
{
	int many = a[0];
	int num = 0;

	for (int i = 1; i < 10; i++)
	{
		if (many < a[i])
		{
			many = a[i];
			num = i;
		}
	}

	printf("가장 많이 나온수=%d\n", num);
}