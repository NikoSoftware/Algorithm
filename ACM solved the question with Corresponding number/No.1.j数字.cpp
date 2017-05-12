#include<stdio.h>
#include<string.h>
long long data[1000000];

void bfs(long long n,long long cur)
{
    if(data[n]!=0)
    {
        printf("%lld %lld %lld\n",n,cur-data[n],cur);
        return;
    }
    data[n]=cur;
    n=n%100000;
    n=n/10;
    n=n*n;
    n=n%1000000;


    bfs(n,cur+1);

}

int main()
{
    long long m;
    while(scanf("%lld",&m)!=EOF)
    {
        memset(data,0,sizeof(data));
        data[m]=0;

        bfs(m,0);
    }


    return 0;
}
