#include<stdio.h>
long long j=20121215;
long long n,i,sum,z;
int main()
{

    while(scanf("%lld",&n)!=EOF)
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
            z=i*i;
            sum+=z%j;
        }
        printf("%lld\n",sum);
    }
}
