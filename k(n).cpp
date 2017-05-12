#include<stdio.h>
int digui(int n)
{
    if(n==1)
    return n;
    if(n%2==0)
    return digui(n-1)*2;
    else
    return digui(n-1)*3;
}
int main()
{
    int n,m;
    scanf("%d",&n);
    m=digui(6);
    printf("%d\n",m);
    return 0;
}
