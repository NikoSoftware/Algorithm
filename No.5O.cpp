#include<stdio.h>
#include<string.h>

int vis[100][100];
int map[100][100];
int n,m;

int so(int i,int j)
{
    if(vis[i][j]>1)
    {
        return vis[i][j];
    }
    int max=1;
    if(map[i][j]>map[i][j-1]&&j-1>=0)
    {
        int h=so(i,j-1)+1;
        if(h>max)
        {
            max=h;
        }
    }
    if(map[i][j]>map[i][j+1]&&j+1<m)
    {
        int h=so(i,j+1)+1;
        if(h>max)
        {
            max=h;
        }
    }
    if(map[i][j]>map[i-1][j]&&i-1>=0)
    {
        int h=so(i-1,j)+1;
        if(h>max)
        {
            max=h;
        }
    }
    if(map[i][j]>map[i+1][j]&&i+1<n)
    {
        int h=so(i+1,j)+1;
        if(h>max)
        {
            max=h;
        }
    }
    return max;
}

int main()
{
        scanf("%d%d",&n,&m);
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&map[i][j]);
                vis[i][j]=1;
            }
        }
        int count=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                vis[i][j]=so(i,j);
                if(vis[i][j]>count)
                {
                    count=vis[i][j];
                }
            }
        }
        printf("%d\n",count);
}
