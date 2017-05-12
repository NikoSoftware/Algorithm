#include<stdio.h>
int main()
{
    int n,m,a[1000],i,j,f,tem,sum;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        sum=0;
        scanf("%d",&m);
        for(j=0;j<m;j++)
        scanf("%d",&a[j]);
        for(j=0;j<m-1;j++)
        {
            for(f=j;f<m;f++)
            {
                if(a[j]>a[f])
                {
                    tem=a[j];
                   a[j]=a[f];
                   a[f]=tem;
                }
            }
        }
        for(j=1;j<m-1;j++)
        {
            if(a[j+1]+a[j-1]!=2*a[j])
            sum=1;
        }
        if(sum)
        printf("no\n");
        else
        printf("yes\n");

    }
}
