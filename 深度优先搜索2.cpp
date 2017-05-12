#include<stdio.h>
#include<string.h>
int n,m;int ans;
int map[100][100];
int vis[100];
void dfs(int cur,int ste)
{
    if(cur==m)
    {
        ans++;
        return;
    }
    for(int j=cur;j<n;j++)
    for(int i=0;i<n;i++)
    if(map[j][i]=='#'&&!vis[i])
    {
        vis[i]=1;
        dfs(j+1,ste+1);
        vis[i]=0;
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==1&&m==-1)break;
        for(int i=0;i<n;i++)scanf("%s",map[i]);
        ans=0;memset(vis,0,sizeof(vis));
        dfs(0,0);
        printf("%d\n",ans);
    }
}
