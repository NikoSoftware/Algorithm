#include<stdio.h>
int p(int n)
{
    int i,p=1;
    for(i=1;i<=n;i++)
    p*=i;
    return p;
}
int main()
{
    int n,i,sum;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        if(n==0)
        printf("1\n");
                else
        {
            for(i=1;i<=n;i++)
        {
            sum+=p(i);
        }
        printf("%d\n",sum);
    }
    }
}
