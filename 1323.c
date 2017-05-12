#include<stdio.h>
int main()
{
    int i,n=10000,sum,j;
    for(i=2;i<n;i++)
    {
        j=i;
        sum=0;
        while(j)
        {
            sum+=(j%10)*(j%10)*(j%10);
            j=j/10;
        }
        if(i==sum)
        printf("%d\n",sum);
    }
    return 0;
}
