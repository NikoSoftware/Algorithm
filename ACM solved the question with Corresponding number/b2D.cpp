#include<stdio.h>
#include<math.h>
int main()
{
    double i,a,b,sum=1,sum1=0;
    scanf("%lf%lf",&a,&b);
    for(i=1;i<=b;i++)
    {
        sum*=1/a;
    }
    sum=1/sum;
    for(i=1;i<=b;i++)
    {
        sum1+=sum*i;
    }
    printf("%.4lf\n",sum1/b);
    return 0;
}
