#include <stdio.h>
#define N 10000
int main()
{
static long int r[N]={1}; /*用long int 是为了保证16位编译器也正常*/
int i,j;
int k=0,l=0;
scanf("%d",&i);
for(j=0;j<=i;j++)
{
r[j]=r[j]*i+k;
k=r[j]/10000;
r[j]=r[j]%10000;
}
if(k)
{
l++;
r[j]=k;
k=0;
}
j=l;
printf("%d!=%d",i,r[j--]);
for(;j>=0;j--)
{
printf("%04d",r[j]);
}
printf("\n");

return 0;
}
