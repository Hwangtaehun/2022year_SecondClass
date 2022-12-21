#include <stdio.h>

#define SIZE 10

int array_equal(int a[], int b[], int size);

int main()
{
	int array1[SIZE] = { 1,2,3,0,0,0,0,0,0,0 };
	int array2[SIZE] = { 0,0,0,0,0,0,0,0,0,0 };

	if (array_equal(array1, array2, SIZE) == 1)
		printf("2개의 배열은 다름\n");
	else
		printf("2개의 배열은 같음\n");

	return 0;
}

int array_equal(int a[], int b[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] != b[i])
			return 1;
	}

	return 0;
}