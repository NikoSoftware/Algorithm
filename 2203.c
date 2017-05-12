#include<stdio.h>
#include<string.h>
int  search(char *a,char *p)
{
    int sum=0;
    while(*a!='\0')
    {
        if(*a==*p)
        {

            return 1;
        }
            a++;
    }
    return 0;
}
int main()
{
    int n;
    char a[500],b;
    while(gets(a)!=NULL)
    {

        n=0;
        scanf("%c",&b);
         getchar();
        n=search(a,&b);
        if(n!=0)
            printf("Found!\n");
        else
            printf("Not found!\n");
    }
    return 0;
}
