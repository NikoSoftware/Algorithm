#include<stdio.h>
int main()
{
    double k,i;
    scanf("%lf",&k);
    while(k>=0)
    {
        ++i;
        k=k-(1/i);
    }
    printf("%.0lf\n",i);
}
