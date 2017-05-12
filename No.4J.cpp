#include<stdio.h>
#include<algorithm>

using namespace std;
int data[10000];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)&&n!=-1&&m!=-1)
    {
        for(int i=0; i<m; i++)
            scanf("%d",&data[i]);
        sort(data,data+m);
        int i = 0, ans = 0;
        while (i < m)
        {
            int s = data[i++];
            while (i < m && data[i] <= s + n) i++;
            int p = data[i - 1];
            while (i < m && data[i] <= p + n) i++;
            ans++;
        }
        printf("%d\n", ans);
    }

}

