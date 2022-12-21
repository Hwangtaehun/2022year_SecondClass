#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y;
	float a, b;
	char op;
	float sum = 0.0f;

	while (1)
	{
		printf("숫자와 사칙연산 기호와 나머지 기호를 입력해주세요. 예시: 10 + 3\n");
		scanf("%d %c %d", &x, &op, &y);

		switch (op)
		{
		case '+':
			sum = x + y;
			break;
		case '-':
			sum = x - y;
			break;
		case '*':
			sum = x * y;
			break;
		case '/':
			/*a = x, b = y;
			sum = a / b;*/
			sum = (float)x / (float)y;
			break;
		case '%':
			sum = x % y;
			break;
		default:
			printf("사용할 수 없는 기호입니다. 다시 입력해주세요.\n");
			break;
		}
		if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%')
		{
			printf("%d %c %d = %.1f\n", x, op, y, sum);
			break;
		}
	}
	return 0;
}