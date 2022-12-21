#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 10

int main()
{
	int storage[SIZE];
	int big, small;

	srand((unsigned)time(NULL));

	for (int i = 0; i < SIZE; i++)
	{
		storage[i] = rand();
	}

	big = storage[0];
	small = storage[0];

	for (int i = 1; i < SIZE; i++)
	{
		if (big < storage[i])
			big = storage[i];
	}
	
	for (int i = 1; i < SIZE; i++)
	{
		if (small > storage[i])
			small = storage[i];
	}

	printf("최대값은 %d\n", big);
	printf("최소값은 %d\n", small);

	return 0;
}