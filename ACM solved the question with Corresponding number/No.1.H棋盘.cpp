#include<stdio.h>
#include<string.h>
int n,s1,s2,d1,d2;
int vis[400][400];
int r[10]= {-2,-1,1,2,2,1,-1,-2},l[10]= {1,2,2,1,-1,-2,-2,-1};

struct Node
{
    int x,y,step;

} node[90000];
void Bfs()
{
    int cont=0,m=1;
    node[0].x=s1;
    node[0].y=s2;
    node[0].step=0;
    vis[s1][s2]=1;
    if(s1==d1&&s1==d2)
    {
        printf("%d",0);
        return;
    }
    while(cont<m)
    {
        for(int i=0; i<8; i++)
        {
            int X=node[cont].x+r[i];
            int Y=node[cont].y+l[i];
            if(X>=0&&X<n&&Y>=0&&Y<n&&vis[X][Y]==0)
            {
                vis[X][Y]=1;
                node[m].x=X;
                node[m].y=Y;
                node[m++].step=node[cont].step+1;
                if(X==d1&&Y==d2)
                {
                    printf("%d",node[m-1].step);
                    return;
                }
            }
        }
        cont++;
    }
}

int main()
{
    int k;
    scanf("%d",&k);
    for(int i=0; i<k; i++)
    {
        scanf("%d",&n);
        scanf("%d%d%d%d",&s1,&s2,&d1,&d2);
        memset(vis,0,sizeof(vis));
        Bfs();
        if(i!=k-1)
        printf("\n");
    }
    return 0;
}
