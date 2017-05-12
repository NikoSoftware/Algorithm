#include<stdio.h>
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n-m>0)
        printf("%d\n",n-m);
        else
        printf("%d\n",m-n);
    }
    return 0;
}
