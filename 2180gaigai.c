#include<stdio.h>
#include<string.h>
long long a[10000],tem,m,i,j,f,z;
int main()
{
    int n,r;

    scanf("%d",&n);
    for(r=0;r<n;r++)
    {
        z=0;
        scanf("%lld",&m);
        for(i=0;i<m;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(i=0;i<m-1;i++)
        {
            for(j=i+1;j<m;j++)
            {
                if(a[i]==a[j])
                {
                    a[i]=0;
                    z++;
                    break;
                }
            }
        }
        f=0;
        for(i=0;i<m-1-f;i++)
        {
            if(a[i]==0)
            {
                a[i]=a[m-1-f];
                f++;
            }
            for(j=i+1;j<m-f;j++)
            {
                if(a[j]==0)
                continue;
               else if(a[i]>a[j])
               {
                   tem=a[i];
                   a[i]=a[j];
                   a[j]=tem;
               }
            }
        }
        printf("%lld",m-z);
        for(i=0;i<m-z;i++)
        printf(" %lld",a[i]);
        printf("\n");
    }
}
