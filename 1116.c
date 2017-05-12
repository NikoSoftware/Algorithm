#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    char a[300],*p;
    gets(a);
    n=strlen(a);
    p=a;
    for(p+=n-1;p>=a;p--)
    printf("%c",*p);
}
