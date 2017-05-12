#include<stdio.h>
int main()
{
    int n,m;
    while(scanf("%d",&n)!=EOF)
    {
        m=0;
        while(n>0)
        {
            m+=n%10;
            n=n/10;
        }
        printf("%d\n",m);
    }
    return 0;
}
