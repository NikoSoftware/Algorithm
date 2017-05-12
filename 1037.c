#include<stdio.h>
#include<string.h>
int main()
{
    int n,a,m,i,*p;
    while(scanf("%d",&n)!=EOF)
    {
        m=n*n*n;
        printf("%d*%d*%d=%d=",n,n,n,m);
        for(i=0;i<n-1;i++)
        {
            a=(n*n-n+1);
            printf("%d+",a+i*2);
        }
        printf("%d\n",a+(n-1)*2);

    }
}
