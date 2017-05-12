#include<stdio.h>
#include<string.h>
int n,m,vis[100],count;
char map[100][100];
void dfs(int x,int cur)
{
    if(x<=n)
    {
        if(cur==m)
            count++;
        else
        {
            for(int i=0; i<n; i++)
            {
                if(map[x][i]=='#'&&vis[i]==0)
                {
                    vis[i]=1;
                    dfs(x+1,cur+1);
                    vis[i]=0;
                }
            }
            dfs(x+1,cur);
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==-1&&m==-1)
            break;
        count=0;
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n; i++)
        {
            scanf("%s",map[i]);
        }
        dfs(0,0);
        printf("%d\n",count);
    }
    return 0;
}
