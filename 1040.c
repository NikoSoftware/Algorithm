#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000],*p;
    int n;
    while(gets(a)!=NULL)
    {
        n=0;
        p=a;
        while(*p!='\0')
        {
            if(*p>='0'&&*p<='9')
            n++;
            p++;
        }
        printf("%d\n",n);
    }
}
