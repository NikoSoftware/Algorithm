#include<stdio.h>
int main()
{
    double i,n,m,j,sum;
    scanf("%lf%lf",&n,&m);
    sum=n;
    for(i=1;i<m;i++)
    {
        sum+=n;
        n=n/2;
    }
    printf("%.2lf %.2lf\n",n/2,sum);
    return 0;
}
