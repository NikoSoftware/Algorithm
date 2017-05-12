#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n,m=0;
    char *p,*q,*c;
    p=(char *)malloc(sizeof(char)*1000);
    q=(char *)malloc(sizeof(char)*1000);
    while(gets(p)!=NULL)
    {
       c=p;
       n=strlen(p)-1;
       while(c!='\0')
       {
           if(*(c+n)>='a'&&*(c+n)<='z')
           {
               *q=*(c+n);
               q++;
           }
           n--;
       }
       printf("%s\n",q);
    }
}
