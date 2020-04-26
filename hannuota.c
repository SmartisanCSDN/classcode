#include"stdio.h"
void hannuota(int x, char a, char b, char c)
{
	if (x == 0)
		return;
	else if (x == 1)
		printf("%c->%c\n", a, c);
	else
	{
		hannuota(x - 1, a, c, b);
		printf("%c->%c\n", a, c);
		hannuota(x - 1, b, a, c);
	}
}
int main()
{
	int x;
	scanf("%d", &x);
	hannuota(x, 'a', 'b', 'c');
	return 0;
}