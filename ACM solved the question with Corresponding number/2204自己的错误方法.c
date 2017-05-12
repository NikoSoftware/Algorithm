#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n;
    char *p,*q,*c,*pnew;
    p=(char *)malloc(sizeof(char)*1000);
    q=(char *)malloc(sizeof(char)*1000);
    while(gets(p)!=NULL)
    {
        pnew=q;
        n=strlen(p);
        c=p+n-1;
        while(c!=p-1)
        {
            if(*c>='a'&&*c<='z')
              {
                *q=*c;
                q++;
              }
                c--;
        }
        *q='\0';

        printf("%s\n",pnew);
    }
}
