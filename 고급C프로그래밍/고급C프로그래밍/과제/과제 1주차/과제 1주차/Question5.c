#include <stdio.h>

int main()
{
	double w, h, area, perimeter;
	w = 10, h = 5;
	area = w * h;
	perimeter = 2 * (w + h);

	printf("사각형의 넓이: %lf\n", area);
	printf("사각형의 둘레: %lf\n", perimeter);

	return 0;
}