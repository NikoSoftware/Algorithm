#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char map[100][100];
int vis[100][100],n,m;
int XX[10]={0,1,0,-1},YY[10]={1,0,-1,0},max,t,o;
void dfs(int x,int y,int cur)
{
    int i;
    if(vis[x][y]==2)
    {
        if(cur>max)
        max=cur;
        printf("max %d\n",max);

    }
    else
    for(i=0;i<4;i++)
    {
        x=x+XX[i];y=y+YY[i];
        if(x>=0&&x<n&&y>=0&&y<m&&vis[x][y]==0)
        {
            vis[x][y]=1;
            printf("x %d y %d \n",x,y);
            dfs(x,y,cur+1);
            vis[x][y]=0;

        }
    }

}



int main()
{
    int i,j,z,k,h;
    scanf("%d",&z);
    while(z--)
    {
        max=0;
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
                    vis[i][j]=-1;
                    k=i;h=j;
                }
                if(map[i][j]=='#')
                vis[i][j]=1;
                if((map[i][j]=='E'))
                {
                    vis[i][j]=2;
                    t=i;o=j;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
        printf("%d",vis[i][j]);
        printf("\n");
        }


        dfs(k,h,0);
        printf("%d\n",max);
    }
    return 0;
}
