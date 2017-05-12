#include<stdio.h>
#include<string.h>
int map[12][12],vis[12],n,too=0;
void dfs(int cur)
{
    int i,j;
    if(cur==n)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n-1; j++)
            {
                printf("%d ",map[i][j]);
            }

        printf("%d\n",map[i][j]);
        }
        printf("\n");
    }
    else for(i=0; i<n; i++)
        {
            int ok=1;
            vis[cur]=i;
            for(j=0; j<cur; j++)
            {
                if(vis[cur]==vis[j]||cur-vis[cur]==j-vis[j]||cur+vis[cur]==j+vis[j])
                {
                    ok=0;
                    break;
                }
            }
            if(ok)
            {
                map[cur][i]=1;
                dfs(cur+1);
                map[cur][i]=0;
            }
        }
}
int main()
{
    scanf("%d",&n);
    memset(map,0,sizeof(map));
    memset(vis,0,sizeof(vis));
    dfs(0);
    return 0;
}
