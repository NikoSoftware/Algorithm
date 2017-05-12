#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node
{
    int a;
    int b;
    int c;

} a[1000];

int cmp(struct Node a,struct Node b)
{
    if(a.a==b.a)
    {
        if(a.b==b.b)
        return a.c<b.c;
        return a.b<b.b;
    }

    return a.a<b.a;

}//如果先按B排序，如果B 相同 按a;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
            scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
        sort(a,a+n,cmp);
        for(int i=0; i<n; i++)
        {
            printf("%d %d %d\n",a[i].a,a[i].b,a[i].c);
        }
        printf("\n");
    }
}
