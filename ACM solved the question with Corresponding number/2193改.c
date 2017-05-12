#include<stdio.h>
int main()
{
    long long c=0,d=0,i,n,tem;
    while(scanf("%lld",&n)!=EOF)
    {   c=0;d=0;
        for(i=1;i<=n;i++)
        {
            c=i*i;
            d=d+c;
        }
        i=d%20121215;
        printf("%lld\n",i);
    }
}
