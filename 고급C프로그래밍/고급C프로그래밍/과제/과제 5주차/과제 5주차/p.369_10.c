#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include<time.h>

int b_rand();

int main() 
{
	int num;
	char c;

	while (1)
	{
		printf("앞면 또는 뒷면(1 또는 0):");
		scanf("%d", &num);
		if (num == 0 || num == 1)
		{
			if (num == b_rand())
			{
				printf("맞았습니다\n");
			}
			else if (num != b_rand())
			{
				printf("틀렸습니다\n");
			}
			getchar();
			while (1)
			{
				printf("계속하시겠습니까?(y 또는 n):");
				scanf("%c", &c);

				if (c == 'n')
				{
					return 0;
				}
				else if (c == 'y')
				{
					break;
				}
				else
				{
					printf("다시입력해주세요.\n");
				}
				getchar();
			}
		}
		else
		{
			printf("다시 입력해주세요.\n");
		}
		
	}
}

int b_rand()
{
	int i;

	srand((unsigned)time(NULL));
	i = rand() % 2;

	return i;
}