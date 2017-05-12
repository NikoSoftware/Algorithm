#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int maxn=1e4;
int n,a[maxn];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            int indexa=lower_bound(a,a+n,a[i])-a;
            int indexb=upper_bound(a,a+n,a[i])-a;
            printf("%d %d\n",indexa,indexb);
        }
        int indexa=lower_bound(a,a+n,-1)-a;
        printf("%d\n",indexa);
    }
    return 0;
}
