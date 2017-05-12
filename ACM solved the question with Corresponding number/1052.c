#include<stdio.h>
int main()
{
    int s,i,j,a;
    scanf("%d",&s);
    a=0;
    while(s>=0)
    {
        ++a;
        s-=a*a*a;
    }
    printf("%d",a-1);
    return 0;
}
