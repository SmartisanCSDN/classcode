#include"stdio.h"
#include"string.h"
void zhuanzhi(char *ch, int left, int right)
{
	char temp;
	while (left<right)
	{
		temp = ch[left];
		ch[left] = ch[right];
		ch[right] = temp;
		left++;
		right--;
	}
}
int main()
{
	int len = 0, left = 0, right = 0;
	char ch[100];
	gets(ch);
	len = strlen(ch);
	zhuanzhi(ch, 0, len - 1);
	while (left < len)
	{
		if (right == ' ' || right == '\0')
		{
			zhuanzhi(ch, left, right);
			left = right + 1;
			right = left;
		}
		else
			right++;
	}
	printf("%s", ch);
	return 0;
}