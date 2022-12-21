#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char check_alpha(char alpha);

int main()
{
	char alpaha;

	while (1)
	{
		printf("문자를 입력하시오: ");
		scanf("%c", &alpaha);

		if (alpaha >= 'a' && alpaha <= 'z')
		{
			alpaha = check_alpha(alpaha);
			printf("%c는 알파벳 문자입니다.", alpaha);
			break;
		}
		printf("다시 입력해주세요");
	}

	return 0;
}

char check_alpha(char alpha)
{
	int change = 0;
	change = 'a' - 'A';
	alpha -= change;
	//printf("%c는 알파벳 문자입니다.", alpha);
}