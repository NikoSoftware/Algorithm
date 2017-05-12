#include<stdio.h>
int main()
{
    int n,a[1000],sum,i;
    while(scanf("%d",&n)!=EOF)
    {
        sum=n;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==1)
            sum--;
        }
        if(n%2==0)
        {
        if(sum%2==0)
        printf("No\n");
        else
        printf("Yes\n");
        }
        else
        printf("Yes\n");
    }
    return 0;
}
