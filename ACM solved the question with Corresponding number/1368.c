#include<stdio.h>
#include<string.h>
int main()
{
    int n,e=0,f=0,g=0,h=0;
    char a[1000],*p;
    gets(a);
    p=a;
    while(*p!='\0')
    {
         if(*p>='A'&&*p<='Z'||*p>='a'&&*p<='z')
        e++;
        else if(*p==' ')
        f++;
        else if(*p>='0'&&*p<='9')
        g++;
        else
        h++;
        p++;
    }
    printf("%d\n%d\n%d\n%d",e,f,g,h);
}
