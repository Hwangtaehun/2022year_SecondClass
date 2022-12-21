#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double radius, area;

	printf("반지름을 입력하시오: ");
	scanf("%lf", &radius);

	area = radius * radius * 3.14;
	printf("원의 면적: %lf", area);
}