#include<stdio.h>
#include<math.h>
int factorial(int n)
{
    int product=1,i;
    for(i=1; i<=n; i++)
    {
        product*=i;
    }
    return product;
}
int main()
{
    int n,i;
    float sum=0;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        sum=sum+1/(factorial(i)*1.0);
          }
          printf("%.4f",sum);
}
