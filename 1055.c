#include<stdio.h>
#include<math.h>
int main()
{
    int i,n;
    float sum=100;
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        sum+=100/pow(2.0,i);
    }
    printf("%.4f",sum);
}
