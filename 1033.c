#include<stdio.h>
int same(int n)
{
    int z,i;
    for(i=2;i<=n;i++)
    {
        if(n%i==0&&40%i==0)
        return 1;
    }
    return 0;
}
int main()
{
    int i;
    for(i=1;i<40;i++)
    if(same(i)==0)
    printf("%d/40,",i);
}
