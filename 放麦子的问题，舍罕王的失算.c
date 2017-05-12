#include<stdio.h>
int main()
{
    int sum=0,i;
    for(i=1;i<=64;i++)
    {
        sum+=i+1;
    }
    printf("%d\n",sum);
}
