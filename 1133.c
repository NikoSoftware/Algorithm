#include<stdio.h>
#include<string.h>
int main()
{
    int a[10000],i,n;
    a[0]=3;a[1]=4;a[2]=5;
    for(i=3;i<40;i++)
    a[i]=a[i-1]+a[i-2]+a[i-3];
    while(scanf("%d",&n)!=EOF)
    printf("%d\n",a[n-1]);
}
