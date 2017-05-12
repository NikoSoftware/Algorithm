#include<stdio.h>
int main()
{
    int i,n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==1)
        printf("0");
        else
            {
                for(i=n-1;i>1;i--)
            {
                if(n%i==0)
                {
                    printf("0");
                return 0;
                }
            }
            printf("1");
            }
            printf("\n");
        }
        return 0;
}
