#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y, z, small = 0;

	printf("3개의 정수를 입력하시오:");
	scanf("%d %d %d", &x, &y, &z);

	small = x;
	if (y < small)
	{
		if (z < small)
			small = z;
		else
			small = y;
	}
	printf("제일 작은 정수는 %d입니다.\n", small);
	return 0;
}