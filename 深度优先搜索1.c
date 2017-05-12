#include<stdio.h>
#include<string.h>
int map[5][5];
int xx[4]={1,0,0,-1};int yy[4]={0,-1,1,0};
int ste;int ans;
void dfs(int x,int y)
{
    if(x==4&&y==4)
    {
        if(cur<ste)
        ste=cur;
    }
    for(int i=0;i<4;i++)
    {
        int X=x+xx[i],Y=y+yy[i];
        if(X>=0&&X<5&&Y>=0&&Y<=5)
        {
            if(!vis[X][Y]&&map[X][Y]==0)
            {
                vis[X][Y]=1;
            }
        }
    }
}
int main()
{
    for(int i=0;i<5;i++)
    for(int j=0;j<5;j++)
    scanf("%d",&map[i][j]);
    ste=10000;
    vis[0][0]=1;
    dfs(0,0,0);
    printf("%d\n",ste);
    printf("(0,0)\n");




    return 0;
}
