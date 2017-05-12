#include<stdio.h>
#include<string.h>
int main()
{
   int n,j,max;
    while(scanf("%d",&n)!=EOF)
    {
        max=n;
            while(n!=0)
    {
        scanf("%d",&n);
        if(max<n)
        max=n;
    }
    printf("%d\n",max);
    }
}
