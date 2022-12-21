#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double Celsius;	   //¼·¾¾
	double Fahrenheit; //È­¾¾

	printf("¼·¾¾ ¿Âµµ¸¦ ÀÔ·ÂÇÏ½Ã¿À: ");
	scanf("%lf", &Celsius);

	Fahrenheit = Celsius / 5 * 9 + 32;

	printf("È­¾¾ ¿Âµµ: %lf\n", Fahrenheit);

	return 0;
}