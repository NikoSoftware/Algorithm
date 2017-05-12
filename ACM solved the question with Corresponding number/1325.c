#include<stdio.h>
int main()
{
    float n,a=2.0,b=1.0,c,i,sum;
    scanf("%f",&n);
    sum=0;
    for(i=1;i<=n;i++)
    {
        sum+=a/b;
        c=b;
        b=a;
        a=a+c;
    }
    printf("%.2f\n",sum);
    return 0;
}
