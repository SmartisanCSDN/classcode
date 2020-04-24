int chazhao(int value[],int x)
{
	int sz=sizeof(value)/sizeof(value[0]);
	int left=0,right=sz-1;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(value[mid]<x)
		{
			left=mid+1;
		}
		else if(value[mid]<x)
		{
			right=mid-1;
		}
		else
		{
			return value[mid];
		}
	}
	if(left>right)
		return -1;
}