#include<stdio.h>
int main()
{
    int a[100],i;
    for(i=0;i<10;i++)
    scanf("%d",&a[i]);
    for(i=9;i>0;i--)
    printf("%d ",a[i]);
    printf("%d",a[0]);
}
