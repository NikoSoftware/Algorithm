#include<stdio.h>
int main()
{
    int n,m,a[100],i,j,f,tem,z;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        z=0;
        for(i=0; i<n-1; i++)
        {
            for(j=i+1; j<n; j--)
            {
                if(a[i]==a[j])
                {
                    for(f=j; f<n-z-1; f++)
                        a[f]=a[f+1];
                    z++;
                }
            }
        }
        for(i=0; i<n-z; i++)
        {
            printf("%d ",a[i]);
        }
        for(i=0; i<n-z-1; i++)
        {
            for(j=i; j<n-z; j++)
              {
               if(a[i]>a[j])
                {
                    tem=a[i];
                    a[i]=a[j];
                    a[j]=tem;
                }
              }
        }
        for(i=0; i<n-z-1; i++)
            printf("%d ",a[i]);
        printf("%d",a[n-z]);

    }
}











