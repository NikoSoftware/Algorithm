#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,i,tem,same;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n>m)
        {
            tem=m;
            m=n;
            n=tem;
        }
        for(i=2;i<=n;i++)
            if(n%i==0&&m%i==0)
                same=i;
        printf("%d\n",n*m/same);
    }
}
