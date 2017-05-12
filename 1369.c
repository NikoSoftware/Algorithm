#include<stdio.h>
int main()
{
    long long sum=1,i;
    for(i=1;i<=30;i++)
    {
        sum+=sum*i;
    }
    printf("%lld",sum);
    return 0;
}

