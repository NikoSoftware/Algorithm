#include<stdio.h>
int dg(int n)
{
    int sum;
    if(n==1)
    return 1;
    sum=dg(n-1)+dj(n);
    return sum;
}
int dj(int n)
{
    int sum1,i;
    sum1=1;
    for(i=1;i<=n;i++)
    sum1*=i;
    return sum1;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)

    {
        printf("%d\n",dg(n));
    }
}

