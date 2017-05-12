#include<stdio.h>
#include<string.h>
int map[10][10],vis[10][10];
int c[100],xx[10]={0,1,0,-1},yy[10]={1,0,-1,0};
typedef struct node
{
    int x;
    int y;
}P;
P point_x[100];
P point_y[100];

void dfs(int x,int y,int cur)
{
    int i,X,Y;
    if(x==4&&y==4)
    {
        for(i=0;i<cur;i++)
        {
            printf("(%d,%d)\n",point_x[i].x,point_y[i].y);
        }
    }
    else
    for(i=0;i<5;i++)
    {
        X=x+xx[i];Y=y+yy[i];
        if(X>=0&&X<5&&Y>=0&&Y<5)
        {
            if(map[X][Y]!=1&&vis[X][Y]!=1)
            {
                vis[X][Y]=1;
                printf("%d %d\n",X,Y);
                point_x[cur].x=X;
                point_y[cur].y=Y;
                dfs(X,Y,cur+1);
            }
        }
    }
}
int main()
{
    int i,j;
    for(i=0;i<5;i++)
    for(j=0;j<5;j++)
    {
        scanf("%d",&map[i][j]);
        vis[i][j]=map[i][j];
    }
    dfs(0,0,0);
    return 0;
}
