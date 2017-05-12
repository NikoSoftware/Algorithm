#include<cstdio>
#include<cstring>
int n;
int c[1001010],vis[1001010];
int lowbit(int x)
{
    return x&(-x);
}
void lpf(int x,int d)
{
    while(x<=n)
    {
        c[x]+=d;
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int cnt=0;
    while(x>0)
    {
        cnt+=c[x];
        x-=lowbit(x);
    }
    return cnt;
}
int main()
{
    int m=0;
    while(~scanf("%d",&n))
    {
        if(n==0)
            break;
        memset(c,0,sizeof(c));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            int d;
            scanf("%d",&d);
            vis[i]=d;
            lpf(i,d);
        }
        char s[10];
        if(m)
            printf("\n");
        printf("Case %d:\n",++m);
        while(~scanf("%s",s))
        {
            int a,b;
            if(strcmp(s,"END")==0)
            {
                break;
            }
            if(s[0]=='S')
            {
                scanf("%d%d",&a,&b);
                lpf(a,b-vis[a]);
                vis[a]=b;
            }
            if(s[0]=='M')
            {
                scanf("%d%d",&a,&b);
                printf("%d\n",sum(b)-sum(a-1));
            }
        }
    }
    return 0;
}
