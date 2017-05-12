#include<stdio.h>
#include<string.h>
int main()
{
    int a=0,b=0,c=0;
    char str[1001],*p;
    while(gets(str)!=NULL)
    {
        a=0,b=0,c=0;
        p=str;
        while(*p!='\0')
        {
            if(*p>='a'&&*p<='z')
            a++;
            else if(*p>='A'&&*p<='Z')
            b++;
            else if(*p>='0'&&*p<='9')
            c++;
            p++;
        }
        printf("%d %d %d\n\n\n",b,a,c);
    }
}
