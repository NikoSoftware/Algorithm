#include<stdio.h>
int main()
{
    double r,PI=3.1415;
    while(scanf("%lf",&r)!=EOF)
    {
        printf("%.3lf\n",4*PI*r*r*r/3);
    }
}
