#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,i,sum1,sum2;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        sum1=0;sum2=0;
        for(i=n;i<=m;i++)
        {
            if(i%2==0)
            sum1+=i*i;
            else
            sum2+=i*i*i;
        }
        printf("%d %d\n",sum1,sum2);
    }
}
