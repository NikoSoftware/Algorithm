#include<stdio.h>
#include<string.h>
int n,m,k,z,r[10]={1,0,0,-1},l[10]={0,1,-1,0},count,vis[100][100];
char map[100][100];

void dfs(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int X=x+r[i];
        int Y=y+l[i];
        if(X>=0&&X<m&&Y>=0&&Y<n&&map[X][Y]=='.'&&vis[X][Y]==0)
        {
            vis[X][Y]=1;
            count++;
            dfs(X,Y);
        }

    }
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        count=0;
        for(int i=0;i<m;i++)
        {
            scanf("%s",map[i]);
            for(int j=0;j<n;j++)
            {
                if(map[i][j]=='@')
                {
                    k=i;
                    z=j;
                }
            }

        }
        dfs(k,z);
        printf("%d\n",count+1);
    }
    return 0;
}
