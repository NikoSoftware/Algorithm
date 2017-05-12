#include<stdio.h>
int main()
{
    int n,i,j,m,a[1000],b[1000];
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        break;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        scanf("%d",&b[i]);

        m=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[j]!=-1)
               if(a[i]>a[j])
               {
                   ++m;
                   a[j]=-1;
                   break;
               }
            }
        }
        if(m>n/2)
        printf("YES\n");
        else
        printf("NO\n");
    }
}
