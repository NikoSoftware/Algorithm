#include<stdio.h>
#include<string.h>
int main()
{
    int a[1000],n,m,i,sum;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
        break;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        {
            if(a[i]>m)
            {
                sum=i;
                break;
            }

        }
        for(i=n;i>sum;i--)
            a[i]=a[i-1];
            a[sum]=m;
        for(i=0;i<n;i++)
        printf("%d ",a[i]);
        printf("%d\n",a[n]);

    }
}
