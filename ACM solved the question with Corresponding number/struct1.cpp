#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node
{
    int a;
    int b;
    bool operator<(const Node &s)const
    {
        if(b==s.b)
            return a<s.a;
        return b<s.b;
    }
} a[1000];
