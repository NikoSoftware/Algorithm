#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000],i;
    while(gets(a)!=NULL)
    {
        for(i=0;i<5;i++)
        {
            printf("%s\n",a);
        }
        printf("\n");
    }
}
