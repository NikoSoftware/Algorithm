#include<stdio.h>
int main()
{
    int i,n,sum=0,sum1=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum+=i;
        sum1+=sum;
    }
    printf("%d",sum1);


    return 0;
}
