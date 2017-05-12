#include<stdio.h>
#include<string.h>
int map[105][105],vis[105][105],n,m;
int a[10]= {-1,0,1,0},b[10]= {0,1,0,-1};

int max(int x,int y)
{
    return x>y?x:y;
}

int dfs(int x,int y)
{
    int X,Y,ans=0;

    if(vis[x][y]!=0)
    {
        return vis[x][y];
    }

    for(int i=0; i<4; i++)
    {
        X=x+a[i];
        Y=y+b[i];

        if(X>0&&X<=n&&Y>0&&Y<=m&&map[X][Y]<map[x][y])
        {
            ans=max(ans,dfs(X,Y));
        }
    }
    vis[x][y]=ans+1;
    return vis[x][y];

}


int main()
{
    int ans=0;
    memset(map,0,sizeof(map));
    memset(vis,0,sizeof(vis));
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {

           ans=max(ans,dfs(i,j));
            //printf("%d ",vis[i][j]);
        }
        //printf("\n");
    }
    printf("%d\n",ans);

    return 0;
}
