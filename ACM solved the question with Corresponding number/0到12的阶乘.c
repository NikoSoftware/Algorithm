#include<stdio.h>
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
         int product=1;
        if(n<0||n>12)
        return 0;
        for(i=1;i<=n;i++)
        {
            product*=i;
        }
        printf("%d\n",product);
    }
    return 0;
}
