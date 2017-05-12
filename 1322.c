#include<stdio.h>
#include<math.h>
int main()
{
    float sum,n,a,b,c,i,j,a1=0,b1=0,c1=0;
    scanf("%f%f%f",&a,&b,&c);
    for(i=1;i<=a;i++)
    a1+=i;
    for(i=1;i<=b;i++)
    b1+=pow(i,2.0);
    for(i=1;i<=c;i++)
    c1+=1/i;
    sum=a1+b1+c1;
    printf("%.2f\n",sum);
}
