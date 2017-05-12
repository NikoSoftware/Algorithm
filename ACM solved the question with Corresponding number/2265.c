#include<cstdio>
#include<cstring>
int n;
int num[100];
int vis[100];
void dfs(int cur)
{
    if(cur>=n)
    {
        for(int i=0;i<n;i++)
        printf("%d ",num[i]);printf("\n");
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            num[cur]=i;vis[i]=1;
            dfs(cur+1);
            vis[i]=0;
        }
    }
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        memset(vis,0,sizeof(vis));
        dfs(0);
    }
}
