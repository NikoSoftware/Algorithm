#include<stdio.h>
int digui(int x,int n)
{
    if(x>n)
    return 0;
    if(x%2==1)
    {
        return x+digui(x+1,n);
    }
    else
    {
        return digui(x+1,n);
    }
}
int main()
{
    int n,i,sum;
    scanf("%d",&n);
    sum=0;
    sum=digui(1,n);
    printf("%d",sum);
    return 0;
}
