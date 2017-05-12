#include<stdio.h>
double n;
int main()
{
    while(scanf("%lf",&n)!=EOF)
    {
        if(n<=0)
        n=-n;
        else if(n<2)
        n=1/n;
        else
        n=n-3;
        printf("%.3lf\n",n);
    }

}
