#include<stdio.h>
#include<math.h>
int main()
{
    int n,m=0,i=0,z;
    scanf("%d",&n);
    for(n;n>0;i++)
    {
         z=n%8;
        n=n/8;
       m+=pow(10,i)*z;
    }
    printf("%d\n",m);
}
