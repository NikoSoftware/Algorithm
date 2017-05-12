#include<cstdio>
#include<cstring>
#include<iostream>

#include<queue>
#include<vector>
using namespace std;

priority_queue< int,vector<int>,greater<int> > q;//从大到小排列。
int n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            int val;
            scanf("%d",&val);
            q.push(val);

        }
        for(int i=0;i<n;i++)
        {
            printf("%d ",q.top());
            q.pop();
        }
        printf("\n");
    }

    return 0;
}
