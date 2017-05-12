#include<stdio.h>
#include<string.h>
char map[100][100];
int vis[100][100],n,m;
int XX[10]={0,1,0,-1},YY[10]={1,0,-1,0},max,t,o;

void dfs(int x,int y,int cur)
{
    int i;//printf("%d %d %d\n",x,y,vis[x][y]);
    if(vis[x][y]==2)
    {
        if(max>cur)
        max=cur;
    }
    else for(i=0;i<4;i++)
    {
        int xx=x+XX[i],yy=y+YY[i];
        if(xx>=0&&xx<n&&yy>=0&&yy<m&&vis[xx][yy]!=1)
        {
            x=xx,y=yy;
            vis[x][y]=(vis[x][y]==0?1:2);
            dfs(x,y,cur+1);
            vis[x][y]=(vis[x][y]==1?0:2);
            //x=x-XX[i];y=y-YY[i];
        }
    }
}
int main()
{
    int i,j,z,k,h;
    scanf("%d",&z);
    while(z--)
    {
        max=10000000;
        memset(map,'.',sizeof(map));
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%s",map[i]);
            for(j=0;j<m;j++)
            {
                if(map[i][j]=='S')
                {
                    vis[i][j]=1;
                    k=i;h=j;
                }
                if(map[i][j]=='#')
                vis[i][j]=1;
                if((map[i][j]=='E'))
                {
                    vis[i][j]=2;
                }
            }
        }
        dfs(k,h,0);
        printf("%d\n",max);
    }
    return 0;
}
