#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    char a[1000],*p;
    while(gets(a)!=NULL)
    {
        n=strlen(a);
        p=a+n-1;
        printf("%s",a);
        while(p!=a-1)
        {
            printf("%c",*p);
            p--;
        }
        printf("\n");
    }
}
