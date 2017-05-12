#include <stdio.h>

const int INF = 10000000; // const 修饰符  INF 表示一个很大的值
const int maxn = 100 + 10; // 数据大小 题目中 0 <= N,M <= 100

int d[maxn][maxn];   //用于储存步数，如，起点为（0,0），那么d[0][0] = 0,表示
                    //从（0,0）到（0,0）的步数，d[1][3]表示从（0,0）到（1,3）的步数
char map[maxn][maxn];  //储存迷宫的地图
int dx[4] = {0,0,-1,1},dy[4] = {-1,1,0,0};// 移动的四个方向
int n,m;

typedef struct //表示一个点
{
    int x,y;
}P;

P que[maxn * 4],s,e,tp,t;  //如同 int a,b,c[1000]一样,只不过这里是P ，是自己定义的类型，一样的用法

int bfs()
{
    int head = 0,tile = 0;
    for (int i = 0;i < maxn;i++)
        for (int j = 0;j < maxn;j++)
            d[i][j] = INF;
    d[s.x][s.y] = 0;
    que[tile++] = s;

    while (head <= tile)
    {
        t = que[head++];

        for (int i = 0;i < 4;i++)
        {
            tp.x = t.x + dx[i];
            tp.y = t.y + dy[i];

            if (0 <= tp.x && tp.x < n &&0 <= tp.y && tp.y < m && map[tp.x][tp.y] != '#' && d[tp.x][tp.y] == INF)
            {
                d[tp.x][tp.y] = d[t.x][t.y] + 1;
                que[tile++] = tp;
            }
        }
    }

    return d[e.x][e.y];
}

int main()
{
    int t,i,j;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d %d",&n,&m);
        for (i = 0;i < n;i++)
            scanf("%s",map[i]);
        for (i = 0;i < n;i++)
            for (j = 0;j < m;j++)
            {
                if (map[i][j] == 'S')
                {
                    s.x = i;
                    s.y = j;
                }
                else if (map[i][j] == 'E')
                {
                    e.x = i;
                    e.y = j;
                }
            }
        printf("%d\n",bfs());
    }
}
