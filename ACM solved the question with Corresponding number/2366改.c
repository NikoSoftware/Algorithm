#include<stdio.h>
#include<math.h>
int primes(int n)
{
    int i,j,sum=0;
    if(n==1)
    return 1;
    if(n==2)
    return 0;
        for(j=2;j<n;j++)
        {
            if(n%j==0)
            {
               sum=1;
               break;
            }
        }
        if(sum==1)
        return 1;
        else
return 0;
}
int main()
{
    int n,i,j,sum;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        for(i=2;i<n;i++)
        {
            if(primes(i)==0&&(primes(n-i)==0))
            {
                sum=1;
                break;
            }
        }
         if(sum==1)
        printf("Yes\n");
        else
        printf("No\n");
    }
}



