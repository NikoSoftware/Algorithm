#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000],*p;
    while(gets(a)!=NULL)
    {
         p=a;
    while(*p!='\0')
    {
        if(*p>='a'&&*p<='z')
        {
            *p=*p-32;
        }
        printf("%c",*p);
         p++;

    }
    printf("\n");
    }
}
