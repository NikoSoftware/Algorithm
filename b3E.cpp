#include<stdio.h>
int main()
{
    int n,i,a[10000],max;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        break;
        a[0]=0;
        a[1]=1;
        max=1;
        for(i=2;i<=n;i++)
        {
            if(i%2==0)
            a[i]=a[i/2];
            else
            a[i]=a[(i)/2]+a[i/2+1];
            if(max<a[i])
            {
                max=a[i];
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
