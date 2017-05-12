#include<stdio.h>
#include<queue>
#include<utiliy>
using namespace std;

const int INF=1000000;
const int maxn=100+10;
int map[maxn][maxn];
int d[maxn][maxn];
int sx,sy,ex,ey;

int dx[4]={0,0,1,1},dy[4]={1,1,0,0};

int que[maxn],head,pop;

/*typedef struct
{
    int x,y;
}p;*/
typedef pair<int,int>p;

int  bfs()
{
    for(int i=0;i<maxn;i++)
    for(int j=0;j<maxn;j++)
    d[i][j]=INF;
    queue<p> q;
    d[sx][sy]=0;
    q.push(p(sx,sy));
    while(q.empty())
    {
         p t=q.front();
        q.pop();
        for(int i=0;i<4; i++)
        {
            int nx=t.front+dx[i];
            int ny=t.second+dy[i];
            if(0<= nx && nx<n&&ny>=0 && ny<m && map[nx][ny]!=1&&
               d[nx][ny]==INF)
            {
                d[nx][ny]=d[t.x][t.y]+1;
                q.push(p(nx,ny));

            }
        }
    }
    return d[ex][ey];
}

int main()
{

}
