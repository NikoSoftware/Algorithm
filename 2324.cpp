#include<stdio.h>
#include<string.h>
int vis[100][100],n,m,c[100];
char map[100][100];
int xx[10]={0,1,1,1,0,-1,-1,-1},yy[10]={1,1,0,-1,-1,-1,0,1};

void dfs(int x,int y)
{
    int i,j,X,Y;
    vis[x][y]=0;
    for(i=0;i<8;i++)
    {
        X=x+xx[i];Y=y+yy[i];
        if(X>=0&&Y>=0&&X<=n&&Y<=m)
        {
            if(vis[X][Y]==1)
            {
                vis[X][Y]=0;
                dfs(X,Y);
            }
        }
    }

}

int main()
{
    int i,j;
    while(~scanf("%d%d",&n,&m)&&n)
    {
        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));
        int sum=0;
        getchar();
        for(i=0; i<n; i++)
        {
            scanf("%s",map[i]);
            for(j=0;j<m;j++)
            if(map[i][j]=='@')
                vis[i][j]=1;
        }

        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            if(vis[i][j]==1)
            {
                dfs(i,j);
                sum++;
            }
        }
        printf("%d\n",sum);
    }


    return 0;
}

