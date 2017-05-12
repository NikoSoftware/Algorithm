#include<stdio.h>
#include<string.h>
#include<stdlib.h>
bool map[200][200],vis[200][200];
int a,b,c,y[5]= {0,1,0,-1},x[5]= {1,0,-1,0};
void Chang(int cur)
{
    for(int i=0; i<cur; i++)
    {
        for(int yy=0; yy<a; yy++)
        {
            for(int xx=0; xx<b; xx++)
                if(vis[yy][xx]==1)
                    for(int j=0; j<4; j++)
                    {
                        int X=xx+x[j],Y=yy+y[j];
                        if(X>=0&&X<b&&Y>=0&&Y<a&&map[Y][X]==0)
                        {
                            map[Y][X]=1;
                        }
                    }
        }
        for(int j=0;j<a;j++)
        for(int t=0;t<b;t++)
        {
            vis[j][t]=map[j][t];
        }
    }
}

int main()
{
    while(scanf("%d",&a)!=EOF)
    {
        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&b,&c);
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                scanf("%d",&map[i][j]);
                vis[i][j]=map[i][j];
            }
        }
        Chang(c);
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b-1; j++)
                {
                    printf("%d ",map[i][j]);
                }
            printf("%d\n",map[i][b-1]);
        }
        printf("\n");
    }

    return 0;
}
