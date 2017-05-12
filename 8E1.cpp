#include<stdio.h>
int map[1000][1000],count=0,min,n,m;
int xx[10]= {0,1,0,-1},yy[10]= {1,0,-1,0};

void dfs(int x,int y,int cnt)
{
    int X,Y;
        for(int i=0; i<4; i++)
        {
            X=x+xx[i];
            Y=y+yy[i];
            if(X>=0&&Y>=0&&X<n&&Y<m&&(map[X][Y]<map[x][y]))
            {
                dfs(X,Y,cnt+1);
            }
        }
        if(count<cnt)
            count=cnt;
}


int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        count=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d",&map[i][j]);
               // if(i==0&&j==0)
                    min=map[i][j];
                //if(min>map[i][j])
                  //  min=map[i][j];
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                //count=0;
                dfs(i,j,1);
               // printf("%d %d %d\n",1,1,count);
            }
        }
        printf("%d\n",count);
    }

    return 0;
}
