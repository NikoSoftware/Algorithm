#include<stdio.h>
#include<string.h>
long long data[20000],c,y;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&c,&y);
            if(i==0)
            data[0]=c;
            for(int j=0;j<i;j++)
            {
                if((data[j]+(i-j)*m)<c)
                {
                    c=data[j]+(i-j)*m;
                }
            }
            data[i]=c;
            sum+=c*y;

        }
        printf("%lld\n",sum);
    }
    return 0;
}
