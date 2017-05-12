#include<stdio.h>
#include<string.h>
#include<memory.h>
int main()
{
    int n;
    char str[1000],*p;
    while(gets(str)!=NULL)
    {
        p=str;
        while(*p!='\0')
        {
            p++;
        }
        n=p-str;
        printf("%d\n",n);
    }
    return 0;
}
