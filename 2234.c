#include<stdio.h>
#include<string.h>
int main()
{
    int n,a[10000],i,j,tem;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]<a[j])
                tem=a[i];
                a[i]=a[j];
                a[j]=tem;
            }
        }
        for(i=0;i<n-1;i++)
        printf("%d ",a[i]);
        printf("%d",a[n-1]);
    }
}
