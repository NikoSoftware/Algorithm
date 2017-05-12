#include<cstdio>
#include<cstring>
#include<stack>

using namespace std;

stack<int> s;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            int val;
            scanf("%d",&val);
            s.push(val);
        }
        while(!s.empty())
        {
            int val=s.top();
            s.pop();
            printf("%d ",val);
        }
        printf("Size %d\n",s.size());
    }
}
