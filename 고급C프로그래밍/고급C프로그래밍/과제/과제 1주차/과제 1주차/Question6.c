#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double Celsius, Fahrenheit;

	printf("È­¾¾ ¿Âµµ¸¦ ÀÔ·ÂÇÏ½Ã¿À: ");
	scanf("%lf", &Fahrenheit);

	Celsius = (Fahrenheit - 32) / 9 * 5;

	printf("¼·¾¾ ¿Âµµ: %lf\n", Celsius);

	return 0;
}