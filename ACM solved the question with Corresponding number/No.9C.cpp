#include <iostream>
#include <stdio.h>
#include<string.h>
#include <cmath>
#include <algorithm>
using namespace std;

int b[500050], c[500050];
int n;

struct node
{
    int num, id;
}a[500050];

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
            scanf("%d", &a[i].num);
            a[i].id = i;
        }
        sort(a+1, a+n+1, cmp);
        b[a[1].id] = 1;
        for(i = 2; i <= n; i++)
        {
            if(a[i].num != a[i-1].num)
                b[a[i].id] = i;
            else b[a[i].id] = b[a[i-1].id];
        }
        ans = 0;
        for(i = 1; i <= n; i++)
        {
            update(b[i], 1);
            ans += (sum(n)-sum(b[i]));
        }
        printf("%I64d\n", ans);
    }

    return 0;
}
