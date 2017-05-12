#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

queue<int> q;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            int val;
            scanf("%d",&val);
            q.push(val);
        }
        while(!q.empty())
        {
            int val=q.front();
            q.pop();
            printf("%d ",val);
        }
        printf("Size %d\n",q.size());
    }
}
