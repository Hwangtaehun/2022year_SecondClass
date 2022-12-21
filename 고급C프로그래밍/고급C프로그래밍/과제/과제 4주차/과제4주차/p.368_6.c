#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int even(int n);
int absolute(int n);
int sign(int n);

int main()
{
	int num;
	printf("정수를 입력하시오:");
	scanf("%d", &num);

	switch (even(num))
	{
	case -1:
		printf("even()의 결과: 양수가 아닙니다.\n");
		break;
	case 0:
		printf("even()의 결과: 홀수\n");
		break;
	case 1:
		printf("even()의 결과: 짝수\n");
		break;
	}

	/*if (even(num) == 1)
		printf("even()의 결과: 짝수\n");
	else if (even(num) == 0)
		printf("even()의 결과: 홀수\n");
	else
		printf("even()의 결과: 양수가 아닙니다.\n");*/

	printf("absolute()의 결과: %d\n", absolute(num));

	switch (sign(num))
	{
	case -1:
		printf("sign()의 결과: 음수\n");
		break;
	case 0:
		printf("sign()의 결과: 0\n");
		break;
	case 1:
		printf("sign()의 결과: 양수\n");
		break;
	}

	/*if (sign(num) == -1)
		printf("sign()의 결과: 음수\n");
	else if (sign(num) == 0)
		printf("sign()의 결과: 0\n");
	else if (sign(num) == 1)
		printf("sign()의 결과: 양수\n");*/

	return 0;
}

int even(int n)
{
	if (n > 0)
	{
		if (n % 2 == 0)
			return 1;
		else if (n % 2 == 1)
			return 0;
	}
	else
		return -1;
}

int absolute(int n)
{
	if (n >= 0)
		return n;
	else
		return -n;
}

int sign(int n)
{
	if (n > 0)
		return 1;
	else if (n == 0)
		return 0;
	else
		return -1;
}