//递归算法
int digui(int i,int n)
{
	if(i==n)
		return 1+n;
	else
		return 1+n*digui(i+1,n);
}
int value(int n)
{
	if(n==1)
		return 1;
	else
		return digui(1,n);
}