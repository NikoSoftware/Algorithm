#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d",&n);
    m=n/10;
    if(m>=9)
    printf("A");
    else if(m==8)
    printf("B");
    else if(m==7)
    printf("C");
    else if(m==6)
    printf("D");
    else
    printf("E");
    return 0;
}
