#include<stdio.h>
#include<string.h>
char map[100][100];
int vis[100][100];
int xx[10]={0,1,0,-1},yy[10]={1,0,-1,0},n,m,G=0;
int dfs(int x,int y)
{
    //getchar();
    //puts("dfsf");
    int i,X,Y;
    for(i=0;i<4;i++)
    {
        X=x+xx[i];Y=y+yy[i];
        if(X>=0&&X<n&&Y>=0&&Y<m&&(map[x][y]==map[X][Y])&&vis[X][Y]!=1)
        {
           // printf("%d %d %c \n",X,Y,map[X][Y]);
            vis[X][Y]=1;
            G++;
            dfs(X,Y);
        }
    }
    //printf("%d\n",G);
    return G;
}
int main()
{
    int k,i,j,max;
    scanf("%d",&k);
    while(k--)
    {
        max=0;
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%s",map[i]);
            for(j=0;j<m;j++)
            if(map[i][j]=='#')
                vis[i][j]=1;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(vis[i][j]!=1)
                {
                    G=0;
                    G=dfs(i,j);
                    if(G>max)
                    max=G;
                }
            }
        }
        printf("%d\n",max*max*5);
    }
    return 0;
}
