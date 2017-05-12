#include<stdio.h>
int main()
{
    int n,max;
    while(scanf("%d",&n)!=EOF)
    {
        max=n;
        while(scanf("%d",&n)!=EOF)
        {
            if(n==-1)
        break;
        if(max<n)
        max=n;
        }
    printf("%d",max);
    }

}
