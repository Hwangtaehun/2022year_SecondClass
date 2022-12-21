#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

void Win();
void Lose();
void Draw();

int main()
{
	int Ct, Cp; // CT: 사용자, CP; 컴퓨터
	Cp = srand((unsigned)time) % 3 + 1;

	while (1)
	{
		printf("선택하시오(1: 가위 2: 바위 3: 보)");
		scanf("%d", &Ct);
		if (Ct == 1)
		{
			if (Cp == 1)
			{
				Draw();
			}
			else if (Cp == 2)
			{
				Lose();
			}
			else
			{
				Win();
			}
			break;
		}
		else if (Ct == 2)
		{
			if (Cp == 1)
			{
				Win();
			}
			else if (Cp == 2)
			{
				Draw();
			}
			else
			{
				Lose();
			}
			break;
		}
		else if (Ct == 3)
		{
			if (Cp == 1)
			{
				Lose();
			}
			else if (Cp == 2)
			{
				Win();
			}
			else
			{
				Draw();
			}
			break;
		}
		else
		{
			printf("잘못 입력했습니다.");
		}
	}

	return 0;
}

void Win()
{
	printf("사용자가 이겼습니다.\n");
}

void Lose()
{
	printf("사용자가 졌습니다.\n");
}

void Draw()
{
	printf("무승부입니다.\n");
}