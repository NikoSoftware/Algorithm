#include <iostream>
#include <stdio.h>
#include<string.h>
#include <cmath>
#include <algorithm>
using namespace std;

int b[500005], c[500005];
int n;

struct node
{
    int num, id;
}a[500005];

bool cmp(node a, node b)
{
    return a.num < b.num;
}

void update(int i, int x)
{
    while(i <= n)
    {
        c[i] += x;
        i += i&(-i);
    }
}

int sum(int i)
{
    int sum = 0;
    while(i > 0)
    {
        sum += c[i];
        i -= i&(-i);
    }
    return sum;
}

int main()
{
    int i;
    long long ans;
    while(scanf("%d", &n), n)
    {
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &a[i].num); //输入数值num
            a[i].id = i;            //记录序号id
        }
        ///开始离散化
        sort(a+1, a+n+1, cmp);  //先排序
        /*因为a[1].num是最小的，id是它的位置，所以b[a[1].id]=1最小，
          最小的数变成1，第二小的变成2，如此类推从而达到离散化*/
        b[a[1].id] = 1;
        for(i = 2; i <= n; i++)
        {
            if(a[i].num != a[i-1].num)
                b[a[i].id] = i;
            else b[a[i].id] = b[a[i-1].id];
        }
        ///离散化完毕
        ans = 0;
        for(i = 1; i <= n; i++)
        {
            update(b[i], 1);
            //这里很巧妙，每一次更新后，判断此数比左边的数小的数有多少
            ans += (sum(n)-sum(b[i]));
        }
        //从而求到：右边的数比左边的数大的个数的总和
        printf("%I64d\n", ans);
    }

    return 0;
}
