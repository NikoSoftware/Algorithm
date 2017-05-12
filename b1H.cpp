#include<stdio.h>
#include<string.h>
#include<math.h>
#include <algorithm>
using namespace std;
int a[10000000],b[100000000];
int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int cur=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(i=n-1;i>sqrt(m)-2||i==sqrt(m)-2;i--)
        for(j=i-1;j>sqrt(m)-3||j==sqrt(m)-3;j--)
        {
            b[cur++]=a[i]+a[j];
        }
        sort(b,b+cur);
        for(i=cur-1;i>cur-m;i--)
        printf("%d ",b[i]);
        printf("%d\n",b[i]);
    }
    return 0;
}
