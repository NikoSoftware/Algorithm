#include<stdio.h>
#include<string.h>
int main()
{
    int a[1000],flag;
    int m,n,i;
    while(scanf("%d",&n)!=EOF)
    {
            memset(a,0,sizeof(a));
        int j=0,z=0;
        scanf("%d",&m);
        while(1)
        {
            for(i=1; i<=n; i++)
            {
                if(a[i]==0)
                    ++j;
                if(a[i]==0&&j%m==0)
                {
                    a[i]=1;
                    ++z;
                }
                if(z==n-1)
                break;
            }
            if(z==n-1)
            break;
        }
        for(i=1; i<=n; i++)
            if(a[i]==0)
                printf("%d\n",i);
    }
    return 0;
}
