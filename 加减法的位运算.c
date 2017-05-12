#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,tem,n,m,binary=0,max;
    cha a[100],b[100],c[120];
    scanf("%s%s",&a,&b);
    n=strlen(a);
    for(i=0;i<n/2;i++)
    {
        tem=a[n-i];
        a[n-i]=a[i];
        a[i]=tem;
    }
    m=strlen(b);
    for(i=0;i<m/2;i++)
    {
       tem=a[m-i];
       a[m-i]=a[i];
       a[i]=tem;
    }
    if(n>m)
    max=n;
    else
    max=m;

}





