#include<stdio.h>
#include<queue.h>
using namespace std;

const int INF=1000000;
const int maxn=100+10;
int map[maxn][maxn];
int d[maxn][maxn];
int sx,sy,ex,ey;

int que[maxn],head,pop;

typedef struct
{
    int x,y;
}p;

int  bfs()
{
    for(int i=0;i<maxn;i++)
    for(int j=0;j<maxn;j++)
    d[i][j]=INF;
    queue<p>q;
    d[sx][sy]=0;
    q.push(p(sx,sy));
}

int main()
{

}
