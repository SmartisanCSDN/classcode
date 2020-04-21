int Fibonacci(int n)
        {
            if(n<=0)
                return 0;
            else
                if(n==1||n==2)
                    return 1;
                else
                {
                    int a=1,b=1,c;
                    for(int i=3;i<=n;i++)
                    {
                        c=a+b;
                        a=b;
                        b=c;
                    }
                    return b;
                }
        }