#include <stdio.h>

array_copy(int a[], int b[], int size);

int main()
{
	int array1[10] = { 1, 2, 3, 0, 0, 0, 0, 0, 0, 0 };
	int array2[10] = { 0 };

	array_copy(array1, array2, 10);
	return 0;
}

array_copy(int a[], int b[], int size)
{
	for (int i = 0; i < size; i++)
	{
		b[i] = a[i];
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", b[i]);
	}
}