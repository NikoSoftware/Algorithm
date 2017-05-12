#include<stdio.h>
int main()
{
    long long n,m,ans;
    int i;
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        ans=1;
        for(i=1;i<=m;i++,n--)
        ans=ans*n/i;
        printf("%lld\n",ans);
    }
    return 0;
}
