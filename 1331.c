#include<stdio.h>
#include<string.h>
int main()
{
    int a[3],b[3],c[3],i;
    for(i=0;i<3;i++)
    scanf("%d",&a[i]);
    for(i=0;i<3;i++)
    scanf("%d",&b[i]);
    for(i=0;i<3;i++)
    scanf("%d",&c[i]);
    for(i=0;i<3;i++)
    printf("%d %d %d \n",a[i],b[i],c[i]);
}
