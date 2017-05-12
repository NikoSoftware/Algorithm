#include<stdio.h>
#include<string.h>

char map[40][40];
int n,m,t,fx,fy,fx1,fy1,vis[40][40],r[10]= {1,0,0,-1},l[10]= {0,1,-1,0};

struct Node
{
    int x,y,step;
}node[50000];

void bfs()
{
    node[0].x=fx;
    node[0].y=fy;
    node[0].step=0;
    vis[fx][fy]=1;
    int cont=0,key=1;
    while(cont<key)
    {
        if(node[cont].x==fx1&&node[cont].y==fy1)
        {
            if(node[cont].step==t)
            {
                printf("YES\n");
            }
            else
                printf("NO\n");
            return;
        }
        else
        {
            if(node[cont].step>t)
            {
                vis[node[cont].x][node[cont].y]=1;
                cont++;
            }
            else
            {
                for(int i=0; i<4; i++)
                {
                    int X=node[cont].x+r[i];
                    int Y=node[cont].y+l[i];
                    if(X>=0&&Y>=0&&X<n&&Y<m)
                    {
                        if(vis[X][Y]==0&&map[X][Y]!='X')
                        {
                            node[key].x=X;
                            node[key].y=Y;
                            node[key++].step=node[cont].step+1;
                        }
                    }
                }
                cont++;
            }
        }
    }
    if(cont>=key)
        printf("NO\n");
}

int main()
{
    while(scanf("%d%d%d",&n,&m,&t)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        if(n==0&&m==0&&t==0)
        {
            break;
        }
        for(int i=0; i<n; i++)
        {
            scanf("%s",map[i]);
            for(int j=0; j<m; j++)
            {
                if(map[i][j]=='S')
                {
                    fx=i;
                    fy=j;
                }
                if(map[i][j]=='D')
                {
                    fx1=i;
                    fy1=j;
                }
            }
        }
        bfs();

    }

    return 0;
}



