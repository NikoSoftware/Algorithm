#include<stdio.h>
int main()
{
    int n,i,j,sum;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        break;
        sum=0;
        while(n>=2)
        {
        n=n/2;
        sum++;
        }
        printf("%d\n",sum);
}
}
