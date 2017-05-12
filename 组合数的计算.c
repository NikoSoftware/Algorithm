#include<stdio.h>
int main()
{
    int i,j,sum,a,b,n,m,z;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        a=1,b=1;
        z=m;
        for(i=n;i>m;i--,z--)
    {
        sum=(i/z);
    }

        printf("%d\n",sum);
    }
}
