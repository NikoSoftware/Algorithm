#include<stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int n,i,a[100000],b[100000];
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        int k,j,cout=0,z=0;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(i=0; i<n; i++)
            scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        k=n-1;
        for(i=n-1; i>=0; i--)
        {
            for(j=k; j>=0; j--)
            {
                if(a[i]>b[j])
                {
                    cout++;
                    k=j-1;
                    break;
                }
                else if(a[i]==b[j])
                {
                    z++;
                    k=j-1;
                    break;
                }
            }
        }
        if(cout>(n-z)/2)
            printf("%d\n",200);
        else
            printf("%d\n",0);
    }


    return 0;
}
