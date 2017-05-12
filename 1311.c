#include<stdio.h>
int main()
{
    double r,h,PI=3.14;
    scanf("%lf%lf",&r,&h);
    printf("C1=%.2lf\n",PI*2*r);
    printf("Sa=%.2lf\n",PI*(r*r));
    printf("Sb=%.2lf\n",4*PI*(r*r));
    printf("Va=%.2lf\n",4*PI*(r*r*r)/3);
    printf("Vb=%.2lf\n",PI*r*r*h-0.00001);
    return 0;
}
