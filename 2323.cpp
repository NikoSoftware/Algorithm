#include<stdio.h>
#include<string.h>
int n;
int map[12][12];
int vis[12];
void dfs(int cur)
{
  if(cur==n)
  {
      for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
      printf("%d%c",map[i][j],j==n-1?'\n':' ');
      printf("\n");
  }
  for(int i=0;i<n;i++)
  {
      int ok=1;
      for(int j=0;j<cur;j++)
      if(vis[j]==i||vis[j]-j==i-cur||vis[j]+j==i+cur)
      ok=0;
      if(ok==0)continue;
      vis[cur]=i;map[cur][i]=1;
      dfs(cur+1);
      vis[cur]=0;
      map[cur][i]=0;
  }
}
int main()
{
    while(~scanf("%d",&n))
    {
        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));
        dfs(0);
    }
}

