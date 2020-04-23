//优化
int value(int n)
{
	int txe=1;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		txe*=i;  //txe为上一个数的阶乘，在乘以这个数即为这个数的阶乘
		sum+=txe;
	}
	return txe;
}