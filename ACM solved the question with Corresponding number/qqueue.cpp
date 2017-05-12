#include<cstdio>
#include<cstring>
#include<iostream>

#include<queue>
#include<vector>
using namespace std;

struct node
{
    int a;
    int b;
    bool operator< (const Node &c)const
    {
        if(b==c.b)
        return a>c.a;
        return b>c.b;
    }
};
priority_queue<Node> q;

int n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            node pnew;
            scanf("%d%d",&pnew.a,&pnew.b);
            q.push(pnew);
        }
        for(int i=0;i<n;i++)
        {
            node pnew;
            scanf("%d %d\n",q.top().a,q.top().b);
            q.pop;
        }
    }
    return 0;
}
