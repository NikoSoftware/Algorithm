#include<stdio.h>
#include<math.h>
long long j=1000000000;
int a[10000];
int main()
{
    int i,n,sum;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<=1||n>=500)
        break;
        a[0]=1;a[1]=1;
        for(i=2;i<=n;i++)
        {
            a[i]=a[i-1]%j+a[i-2]%j;
        }
     printf("%09d\n",a[n]);
    }
}
