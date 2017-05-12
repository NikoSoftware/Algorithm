#include<stdio.h>
#include<string.h>
 long long n,m,i,j;
int main()
{
     int sum,sum1,sum2;
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        sum1=0;
        sum2=0;
        if(n<2)
        n=2;
        for(i=n;i<m;i++)
        {
             sum=0;
            for(j=2;j<i;j++)
            {
                if(i%j==0)
                {
                    sum=1;
                    break;
                }
            }
            if(sum==0&&sum2==1)
            printf(" %lld",i);
            else if(sum==0)
            {
                printf("%lld",i);
                sum1=1;
                sum2=1;
            }
        }
        if(sum1==0)
        printf("-1");
        printf("\n");
    }
}
