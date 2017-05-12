#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *search(char *ps,char *pc)
{
    while(*ps!='\0')
    {
        char *p1=ps,*p2=pc;
        int flag=1;
        while(*p2!='\0')
        {
            if(*p1!=*p2)
            {
                flag=0;
                break;
            }
            p1++;
            p2++;
        }
        if(flag)
        {
            return pc;
        }
        ps++;

    }
    return NULL;
}
int main()
{
    char a[500],b[500];
    while(gets(a)!=NULL)
    {
        //getchar();
        gets(b);
    if(search(a,b)==NULL)
    printf("NO!\n");
    else
    printf("YES!\n");
    }

}











