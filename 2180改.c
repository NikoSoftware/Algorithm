#include<stdio.h>
#include<string.h>
int main()
{
    int n,j,i,m,z,r,f;
    int tem,a[10000];
    scanf("%d",&n);
    for(r=0;r<n;r++)
    {
        z=0;
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<m-1;i++)
        {
            for(j=i+1;j<m;j++)
            {
                if(a[i]==a[j])
                {
                    a[i]=0;
                    z++;
                }
            }
        }
            f=0;
            for(i=0;i<m-2;i++)
            {
                if(a[i]==0)
                {
                    a[i]=a[m-1-f];
                     f++;
                }
                for(j=i+1;j<m-1-f;j++)
                {
                    if(a[j]==0)
                    continue;
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
        printf(" %d",a[i]);
        printf("\n");
    }
}










