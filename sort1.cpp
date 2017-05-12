#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    int n,a[100];
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        sort(a,a+n);
        int m=unique(a,a+n)-a;
        for(int i=0;i<m;i++)
        printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
