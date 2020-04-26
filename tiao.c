#include"stdio.h"
int tiao(int n, int m)
{
	if ((n == 1 || n == 0) && m > 0)
		return 1;
	else
	{
		int count = 0;
		for (int i = 1; i <= n && i <= m; i++)
			count += tiao(n - i, m);
		return count;
	}
}
int main()
{
	int n, m;
	while (1)
	{
		scanf("%d%d", &n, &m);
		printf("%d\n", tiao(n, m));
	}
	return 0;
}