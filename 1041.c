#include<stdio.h>
#include<string.h>
int main()
{
    int a[1000],i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        a[0]=1;
        a[1]=1;
        for(i=2;i<900;i++)
        {
            a[i]=a[i-1]+a[i-2];
        }
        for(i=0;i<n;i++)
        printf("%d ",a[i]);
        printf("\n");

    }
}
