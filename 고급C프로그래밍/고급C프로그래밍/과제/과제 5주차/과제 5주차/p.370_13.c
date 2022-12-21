#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_multiple(int n, int m);

int main()
{
	int first_num, second_num;

	printf("첫번째 정수를 입력하시오:");
	scanf("%d", &first_num);
	printf("두번째 정수를 입력하시오:");
	scanf("%d", &second_num);

	switch (is_multiple(first_num, second_num))
	{
	case 0:
		printf("배수가 아닙니다.\n");
		break;
	case 1:
		printf("%d는 %d의 배수입니다.\n", first_num, second_num);
		break;
	}

	return 0;
}

int is_multiple(int n, int m)
{
	int result = 0;

	result = n % m;

	if (result == 0)
		return 1;

	return 0;
}