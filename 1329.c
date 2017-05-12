#include<stdio.h>
int main()
{
    int n,i,j,sum;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        sum=0;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            sum=1;
        }
        if(sum==0)
            printf("%d\n",i);
    }
}
