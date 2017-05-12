#include<stdio.h>
int main()
{
    long long n,z=0;
    while(scanf("%lld",&n)!=EOF)
    {
        z++;
        printf("Case #%lld:\n%lld\n",z,n/2+1);
    }
}
