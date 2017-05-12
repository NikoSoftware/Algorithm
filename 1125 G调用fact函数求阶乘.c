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
    while(scanf("%d",&n)!=EOF)
    {
     double sum=0;
    for(i=1;i<=n;i++)
    {
        sum+=1/fact(i);
    }
    printf("sum=");
    printf("%.5lf\n",sum);

    }
        return 0;
}
