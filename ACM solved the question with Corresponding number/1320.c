#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,j,sum=0,m=0;
    scanf("%d",&n);
    for(i=0;i<5;i++)
    {
        for(j=0;j<=i;j++)
         {
             m+=n*pow(10.0,j);
         }
    }
    printf("%d",m);
}
