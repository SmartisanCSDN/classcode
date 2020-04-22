#include"stdio.h"
#include"string.h"
#include"math.h"
void ten_two()
{
	int value, i;
	int c[100];
	printf("请输入十进制数:>");
	scanf("%d", &value);
	for (i = 0;;)
	{
		if (value <= 1)
		{
			c[i] = value;
			break;
		}
		c[i] = value % 2;
		value /= 2;
		++i;
	}
	printf("二进制数为:");
	for (; i >= 0;)
	{
		printf("%d", c[i]);
		--i;
	}
	printf("\n");
}
void two_ten()
{
	char value[100];
	int s = 0, i;
	printf("请输入二进制数:>");
	scanf("%s", value);
	for (i = 0; i<strlen(value); i++)
		s += (value[i] - 48)*(int)pow(2, strlen(value) - 1 - i);
	printf("十进制数为:%d\n", s);
}
int main()
{
	int k;
	while (1)
	{
		printf("[1]十进制转二进制  [2]二进制转十进制  [0]退出\n");
		printf("请选择:>");
		scanf("%d", &k);
		if (k == 0)
			break;
		switch (k)
		{
		case 1:
			ten_two();
			break;
		case 2:
			two_ten();
			break;
		default:
			printf("输入错误，请重新选择！");
		}
	}
	printf("退出系统,byebye...\n");
	return 0;
}
