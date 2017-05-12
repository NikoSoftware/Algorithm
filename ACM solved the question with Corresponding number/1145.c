#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000],max,*p;
    while(gets(a)!=NULL)
    {
        p=a;
        max=*p;
        while(*p!='\0')
        {
            if(max<*p)
            max=*p;
            p++;
        }
        p=a;
        while(*p!='\0')
        {
            printf("%c",*p);
            if(*p==max)
            printf("(max)");
            p++;
        }
        printf("\n");
    }
}
