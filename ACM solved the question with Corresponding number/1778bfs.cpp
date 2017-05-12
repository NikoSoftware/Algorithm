#include <stdio.h>

const int INF = 10000000; // const ���η�  INF ��ʾһ���ܴ��ֵ
const int maxn = 100 + 10; // ���ݴ�С ��Ŀ�� 0 <= N,M <= 100

int d[maxn][maxn];   //���ڴ��沽�����磬���Ϊ��0,0������ôd[0][0] = 0,��ʾ
                    //�ӣ�0,0������0,0���Ĳ�����d[1][3]��ʾ�ӣ�0,0������1,3���Ĳ���
char map[maxn][maxn];  //�����Թ��ĵ�ͼ
int dx[4] = {0,0,-1,1},dy[4] = {-1,1,0,0};// �ƶ����ĸ�����
int n,m;

typedef struct //��ʾһ����
{
    int x,y;
}P;

P que[maxn * 4],s,e,tp,t;  //��ͬ int a,b,c[1000]һ��,ֻ����������P �����Լ���������ͣ�һ�����÷�

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
