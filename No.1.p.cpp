#include<stdio.h>
#include<string.h>
char map[300][300];
int n,m,sx,sy,ex,ey,vis[300][300],r[10]= {-1,0,1,0},l[10]= {0,1,0,-1},count;

void dfs(int x,int y,int cur)
{
    if(cur<count)
    {

        if(x==ex&&y==ey)
        {
            if(cur<count)
            {
                count=cur;
            }
        }
        else
            for(int i=0; i<4; i++)
            {
                int X=x+r[i];
                int Y=y+l[i];
                if(X>=0&&X<n&&Y>=0&&Y<m&&map[X][Y]!='#'&&vis[X][Y]==0)
                {
                    vis[X][Y]=1;
                    if(map[X][Y]=='x')
                        dfs(X,Y,cur+2);
                    else
                        dfs(X,Y,cur+1);
                    vis[X][Y]=0;
                }
            }
    }
}



int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        count=100000;
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n; i++)
        {
            scanf("%s",map[i]);
            for(int j=0; j<m; j++)
            {
                if(map[i][j]=='r')
                {
                    sx=i;
                    sy=j;
                }
                if(map[i][j]=='a')
                {
                    ex=i;
                    ey=j;
                }
            }
        }
        vis[sx][sy]=1;
        dfs(sx,sy,0);
        if(count==100000)
            printf("Poor ANGEL has to stay in the prison all his life.");
        else
            printf("%d\n",count);

    }
    return 0;
}
