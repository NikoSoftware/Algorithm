#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int a[1005],dp[1005],c[1005],n;

int bin(int size,int k)
{
    int l = 1,r = size;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(k>c[mid] && k<=c[mid+1])
            return mid+1;
        else if(k<c[mid])
            r = mid-1;
        else
            l = mid+1;
    }
}

int LIS()
{
    int i,j,ans=1;
    c[1] = a[1];
    dp[1] = 1;
    for(i = 2; i<=n; i++)
    {
        if(a[i]<=c[1])
            j = 1;
        else if(a[i]>c[ans])
            j = ++ans;
        else
            j = bin(ans,a[i]);
        c[j] = a[i];
        dp[i] = j;
    }
    return ans;
}

int main()
{
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i = 1; i<=n; i++)
            scanf("%d",&a[i]);
        printf("%d\n",LIS());

    }

    return 0;
}
