#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;

const int maxn=1100;
int n,t[maxn];

struct node
{
    int x,y;
    bool operator < (node a)const
    {
        return x<a.x;
    }
};


int main()
{
    priority_queue<node > q;
    node a={15,32};
    q.push(a);
    a={33,45};
    q.push(a);
    a={20,29};
    q.push(a);
    for(int i=0;i<3;i++)
    printf("top %d %d\n",q.top().x,q.top().y,q.pop());

}


