#include<stdio.h>
#include<math.h>
double fact(int i)
{
    int j;
    double product=1.0;
    for(j=1;j<=i;j++)
    {
        product*=j;
    }
    return product;
}
int main()
{
    int n,i;
    double x,sum=0;
    while(scanf("%lf%d",&x,&n)!=EOF)
   {
       for(i=1;i<=n;i++)
    {
        sum+=pow(-1.0,i-1)*pow(x,i)/fact(i);
    }
    printf("%.4lf\n",sum);
   }
   return 0;
}











