#include<stdio.h>
#include<string.h>
bool v[1000000000];
void prin()
{
    int i,j,n=1000000000;
    v[0]=v[1]=1;
    for(i=2; i<=n; i++)
    {
        if(!v[i])
        {
            for(j=i+i; j<=n; j+=i)
                v[j]=1;
        }
    }
}
int main()
{
    int n,z,h,f,k,x,u;
    int a[1000];
    while(scanf("%d",&n)!=EOF)
    {
        prin();
        for(z=0; z<n; z++)
        {
            long long sum=1,sum2=0;
            scanf("%d",&k);
            x=u=k;
            while(1)
            {
                if(v[++u]==0)
                {
                    k=u;
                    break;
                }
            }
            for(int i=2; i<=k; i++)
            {
                if(v[i]==0)
                    sum*=i;
            }
            for(int i=2; i<=x; i++)
            {
                if(v[i]==0)
                {
                    u=i;
                    while(1)
                    {
                        if(v[++u]==0)
                        {
                            f=u;
                            break;
                        }
                    }
                    sum2+=sum/f/i;
                }
            }
            printf("Case #%d: %lld/%lld\n",z+1,sum2,sum);
        }
    }
return 0;
}
