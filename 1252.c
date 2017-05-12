#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,i,z,k,a[10000],sum;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        sum=0;
        memset(a,0,sizeof(a));
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&z,&k);
            for(; z<=k; z++)
                a[z]=1;
        }
        for(i=0; i<=n; i++)
        {
            if(a[i]==0)
                sum++;
        }
        printf("%d\n",sum);
    }
}
