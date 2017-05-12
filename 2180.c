#include<stdio.h>
#include<string.h>
unsigned long long tem,a[10000001];
int main()
{
int n,m,r,i,j,z;

    scanf("%d",&n);

        for(r=0;r<n;r++)
        {
            z=0;
            scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(i=0;i<m-1-z;i++)
        {
           for(j=i+1;j<m-z;j++)
           {
               if(i==j)
               continue;
               if(a[i]==a[j])
               {
                   a[i]=a[m-1-z];
                   z++;
               }
           }
        }
        for(i=0;i<m-z-1;i++)
        {
            for(j=i+1;j<m-z;j++)
            {
                if(a[i]>a[j])
                {
                    tem=a[i];
                    a[i]=a[j];
                    a[j]=tem;
                }
            }
        }
        printf("%d",m-z);
        for(i=0;i<m-z;i++)
        printf(" %lld",a[i]);
        printf("\n");
    }
}
