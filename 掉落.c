#include<stdio.h>
int main()
{
    int i,sum,n;
    float m=100;
    scanf("%d",&n);
    sum=100;
    for(i=1;i<n;i++)
    {
        sum+=200/2;
        m=m/2;
    }
    printf("%d %.2f\n",sum,m);
   return 0;
}
