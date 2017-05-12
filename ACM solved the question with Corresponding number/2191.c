#include<stdio.h>
int main()
{
    int i,n,m,sum;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum=0;
        scanf("%d",&m);
        if(m%2!=0)
        {
            printf("Case %d: %d\n",i,1);
            continue;
        }
        while(m>1)
        {
            sum++;
            m=m/2;
        }
        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}
