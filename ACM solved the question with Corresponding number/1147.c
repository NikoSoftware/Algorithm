#include<stdio.h>
int main()
{
    int n,i,sum;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        if(n==2)
        printf("Y\n");
        else
        {
            for(i=2;i<n;i++)
        {
            if(n%i==0)
            {
                sum=1;
                break;
            }
        }
        if(sum==0)
        printf("Y\n");
        else
        printf("N\n");
        }
    }
}
