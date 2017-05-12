#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    double a,b,c,d,n,i,k;
    scanf("%lf",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        double s=3.1415926*c*c;
        k=abs(d-b);
        if(k>c)
        k=2*c-k;
        double s1=s*(acos(k/c)/2/3.1415926)*2-k*sqrt(c*c-k*k);
        printf("%lf\n",s1);
    }
    return 0;
}
