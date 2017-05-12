#include<stdio.h>
int main()
{
    int n,i,sum,j=0;
    while(scanf("%d",&n)!=EOF)
    {
        j++;
        sum=0;
        if(n==1)
        printf("Case %d: No\n",j);
        else
        {
            for(i=2;i<n;i++)
         {
             if(n%i==0)
             sum=1;
         }
         if(sum==0)
         printf("Case %d: Yes\n",j);
         else
         printf("Case %d: No\n",j);
    }
    }
}
