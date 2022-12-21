#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num;
	int sum = 0;

	while (1)
	{
		printf("숫자를 입력해주세요.(단 10000을 넘으면 안됩니다.)");
		scanf("%d", &num);

		if (num < 10000)
		{
			for (int i = 1; i <= num; i++)
			{
				sum += i;
			}
			printf("1부터 %d까지 합이 %d입니다.\n", num, sum);
			break;
		}
		else
		{
			printf("다시 입력해주세요.\n");
		}
	}

	return 0;
}