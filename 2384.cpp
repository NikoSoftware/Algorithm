#include<stdio.h>
#include<string.h>
#include<math.h>
long long a[10000],n;
long long God(long long a,long long b)
{
    if(b==0)
    return a;
    return God(b,a%b);
}
void yueshu()
{
    long long i,j,m;
    m=a[0];
    for(i=1;i<n;i++)
    {
        m=God(m,a[i]);
    }
    printf("%lld\n",m);

}
int main()
{
    long long i,j,m;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
        continue;
            else
            {
                memset(a,0,sizeof(a));
                i=0;
                for(i=0; i<n; i++)
                    scanf("%lld",&a[i]);
                yueshu();
            }
    }
    return 0;
}
