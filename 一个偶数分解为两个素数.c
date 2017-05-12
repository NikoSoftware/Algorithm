#include<stdio.h>
int prime(int n)
{
    int i;
     if(n==2)
     return 1;
    for(i=2;i<n;i++)
    {

        if(n%i==0)
        {
          return 0;
        }
    }
    return 1;
}
int main()
{
    int n,i,j,diff,sum;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        for(i=2;i<=(n/2);i++)
        {
            if(prime(i)==0)
            continue;
            diff=n-i;
            if(prime(diff)==0)
           continue;

            sum++;
        }
     printf("%d\n",sum);
    }
}




