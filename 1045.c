#include<stdio.h>
int main()
{
    long long n,a,i,j,sum,m;
    while(scanf("%lld%lld",&a,&n)!=EOF)
    {
        sum=0,m=0;
        for(i=0;i<n;i++)
        {
            m=m*10+a;
            sum+=m;
        }
        printf("%lld\n",sum);
    }
}
