#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,str[10];
    int * p,*z;
    for(i=0;i<10;i++)
    {
        scanf("%d",&str[i]);
    }
    p=str;
    z=p;
    for(p=p+9;p>=z;p--)
    {
        printf("%d",*p);
    }
}
