#include<stdio.h>
#include<string.h>
const int N = 40005;
int sum[N], level[N];

int lowbit(int x)
{
    return x & (-x);
}

int get_sum(int x)
{
    int s = 0;
    while(x > 0)
    {
        s += sum[x];
        x -= lowbit(x);
    }
    return s;
}

void update(int x)
{
    while(x < 40005)
    {
        sum[x]++;
        x += lowbit(x);
    }
}

int main()
{
    int n, x, y, i;
    while(~scanf("%d",&n))
    {
        memset(sum, 0, sizeof(sum));
        memset(level, 0, sizeof(level));
        for(i = 0; i < n; i++)
        {
            scanf("%d%d",&x,&y);
            level[get_sum(x+1)]++;
            update(x+1);
        }
        for(int i=0;i<50;i++)
        printf("%d ",sum[i]);
        for(i = 0; i < n; i++)
            printf("%d\n",level[i]);
    }
    return 0;
}
