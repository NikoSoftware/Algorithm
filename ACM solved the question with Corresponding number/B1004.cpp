#include<stdio.h>
int main()
{
    int n,i;
    double sum,a;
    for(i=0;i<12;i++)
    {
        scanf("%lf",&a);
        sum+=a;
    }
    printf("%lf\n",sum/12);
}
