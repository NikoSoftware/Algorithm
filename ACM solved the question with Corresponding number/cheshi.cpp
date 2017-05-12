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
            scanf("%d", &a[i].num); //������ֵnum
            a[i].id = i;            //��¼���id
        }
        ///��ʼ��ɢ��
        sort(a+1, a+n+1, cmp);  //������
        /*��Ϊa[1].num����С�ģ�id������λ�ã�����b[a[1].id]=1��С��
          ��С�������1���ڶ�С�ı��2��������ƴӶ��ﵽ��ɢ��*/
        b[a[1].id] = 1;
        for(i = 2; i <= n; i++)
        {
            if(a[i].num != a[i-1].num)
                b[a[i].id] = i;
            else b[a[i].id] = b[a[i-1].id];
        }
        ///��ɢ�����
        ans = 0;
        for(i = 1; i <= n; i++)
        {
            update(b[i], 1);
            //��������ÿһ�θ��º��жϴ�������ߵ���С�����ж���
            ans += (sum(n)-sum(b[i]));
        }
        //�Ӷ��󵽣��ұߵ�������ߵ�����ĸ������ܺ�
        printf("%I64d\n", ans);
    }

    return 0;
}
