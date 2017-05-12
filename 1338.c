#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    char a[1000],*p;
    gets(a);
    n=strlen(a);
    p=a;
    while(1)
    {
        printf("%c",*(p+n-1));
        n--;
        if(n==0)
        break;
    }
    return 0;
}
