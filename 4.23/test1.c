//1~n的阶乘求和
int value(int n)
{
	int txe=1;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		txe=1;   //每次算完阶乘归一必不可少
		for(int j=1;j<=i;j++)
			txe*=j;
		sum+=txe;
	}
	return txe;
}