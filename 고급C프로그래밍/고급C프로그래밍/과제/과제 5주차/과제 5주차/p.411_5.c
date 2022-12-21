#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Sum(int n);

int main() 
{
	int num;

	printf("정수를 입력하시오: ");
	scanf("%d", &num);
	
	printf("1부터 %d까지의 합=%d\n", num, Sum(num));

	return 0;
}

int Sum(int n)
{
	if (n <= 1)
		return 1;
	else
		return n + Sum(n - 1);
}