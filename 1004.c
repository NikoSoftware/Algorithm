#include<stdio.h>
int main()
{
    int a,b,n,m,i,tem;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
      scanf("%d%d",&a,&b);
    if(a<b)
    {
        tem=b;
        b=a;
        a=tem;
    }
    printf("Case #%d: %d\n",i,a-b);
    }
}
