#include<stdio.h>
#include<string.h>
int main()
{
    int n,a[1000],i,m,b[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    scanf("%d",&m);
    for(i=0;i<m;i++)
    b[i]=a[n-m+i];
    for(i=n-m-1;i>=0;i--)
    a[i+m]=a[i];
    for(i=0;i<m;i++)
    a[i]=b[i];
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}
