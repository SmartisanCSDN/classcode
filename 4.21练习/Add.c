#include"stdio.h"
int Add(int num1, int num2)
{
	int c = 0, d = 0;
	while (1)
	{
		c = (num1&num2)<<1;
		d = num1^num2;
		if (c == 0)
			break;
		num1 = c;
		num2 = d;
	}
	return d;
}
int main()
{
	int num1, num2, sum = 0;
	scanf("%d%d", &num1, &num2);
	sum = Add(num1, num2);
	printf("%d\n", sum);
	return 0;
}