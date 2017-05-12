#include<stdio.h>
int main()
{
    long long n,i,m,j,z,k,a;
    while(scanf("%lld",&z)!=EOF)
    {
    for(k=1;k<=z;k++)
    {
        int flag=0;
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&m);
            if(i==1)
            a=m-1;
            if(m!=a+i&&flag==0)
            {
                printf("Case #%lld: %lld\n",k,i);
                flag=1;
            }
        }
    }
    }
    return 0;
}
