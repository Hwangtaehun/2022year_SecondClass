#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	printf("숫자를 입력하세요\n");
	scanf("%d", &n);
	if (n >= 100)
		printf("large\n");
	else
		printf("small\n");

	return 0;
}