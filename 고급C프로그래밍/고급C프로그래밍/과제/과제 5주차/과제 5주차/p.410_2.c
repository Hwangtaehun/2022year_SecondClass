#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void get_dice_face(int n);

int main() 
{
	int cnt = 0;
	srand((unsigned)time(NULL));
	get_dice_face(cnt);
	return 0;
}

void get_dice_face(int n)
{
	int cnt_1 = 0;
	int cnt_2 = 0;
	int cnt_3 = 0;
	int cnt_4 = 0;
	int cnt_5 = 0;
	int cnt_6 = 0;
	int side = 0;

	while (n < 100)
	{
		side = rand() % 6 + 1;
		switch (side)
		{
		case 1:
			cnt_1++;
			break;
		case 2:
			cnt_2++;
			break;
		case 3:
			cnt_3++;
			break;
		case 4:
			cnt_4++;
			break;
		case 5:
			cnt_5++;
			break;
		case 6:
			cnt_6++;
			break;
		}
		n++;
	}

	printf("1->%d\n", cnt_1);
	printf("2->%d\n", cnt_2);
	printf("3->%d\n", cnt_3);
	printf("4->%d\n", cnt_4);
	printf("5->%d\n", cnt_5);
	printf("6->%d\n", cnt_6);
	/*int result = cnt_1 + cnt_2 + cnt_3 + cnt_4 + cnt_5 + cnt_6;
	printf("รัวี = %d\n", result);*/
}