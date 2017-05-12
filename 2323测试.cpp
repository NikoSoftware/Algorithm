#include<stdio.h>
#include<string.h>
int map[12][12];
int vis[12],n,too=0;
void dfs(int cur)
{
    printf("%d~~~\n",cur);
    int i,j;
    if(cur==n)
    {
        too++;
        printf("%d\n",too);
    }
    else for(i=0; i<n; i++)
        {
            int ok=1;
            vis[cur]=i;
            printf("%d\n",i);
            for(j=0; j<cur; j++)
            {
                if(vis[cur]==vis[j]||cur-vis[cur]==j-vis[j]||vis[cur]+cur==j+vis[j]);
                {
                    ok=0;
                    break;
                }
            }
            if(ok)
                dfs(cur+1);
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
