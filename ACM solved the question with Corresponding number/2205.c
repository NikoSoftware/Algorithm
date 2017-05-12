#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char *p,*q,*c;
    p=(char *)malloc(sizeof(char)*1000);
    q=(char *)malloc(sizeof(char)*1000);
    while(gets(p)!=NULL)
    {
        gets(q);
        c=p;
        while(*c!='\0')
        {
          c++;
        }
        while(*q!='\0')
        {
            *c=*q;
            c++;
            q++;
        }
        *c='\0';
        //printf("%s\n",c)
        printf("%s\n",p);
    }
}
