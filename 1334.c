#include<stdio.h>
int main()
{
    int i,j,n,m,yue,bei,flag,tem;
    scanf("%d%d",&n,&m);
    if(n>m)
    {
        tem=n;
        n=m;
        m=tem;
    }
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            if(m%i==0)
            {
                yue=i;
            }
        }
    }
    printf("%d %d",yue,n*m/yue);

}
