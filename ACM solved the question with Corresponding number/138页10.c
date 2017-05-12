#include<stdio.h>
double px(double x,int n)
{
    int z;
    if(n==1)
    return x;
    else
    z=x*(1+px(x,n-1));
    return z;
}
int main()
{
    double x,n;
    scanf("%lf%lf",&x,&n);
    printf("%.2lf",px(x,n));
}
