#include<stdio.h>
int main()
{
    int n,m,sum,i;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        scanf("%d",&m);
    for(i=0;i<=m;i++)
    {
        sum+=n+i;
    }
    printf("%d\n",sum);
    }
}
