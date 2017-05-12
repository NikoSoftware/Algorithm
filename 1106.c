#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000],n,m,*p;
    while(gets(a)!=NULL)
    {
        if(strcmp(a,"End of file")==0)
        break;
        p=a;
        while(*p!='\0')
        {
            if(*p==' ')
            {
                p++;
            continue;
            }
            printf("%c",*p);
            p++;
        }
        printf("\n");
    }
}
