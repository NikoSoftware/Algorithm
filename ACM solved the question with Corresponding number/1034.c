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
            if(*p>='A'&&*p<='Z')
            *p=*p-'A'+'a';
            p++;
        }
        printf("%s\n",a);
    }
}
