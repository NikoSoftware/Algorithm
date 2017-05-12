#include<stdio.h>
int main()
{
    char a[1000];
    while(gets(a)!=EOF)
    {
        printf("%s",a);
    }
    return 0;
}
