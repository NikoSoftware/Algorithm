#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    char a[100];
    while(gets(a)!=NULL)
    {
        n=strlen(a);
        for(i=0;i<n-1;i++)
        {
            if(a[i+1]=='\')
            if(a[i]=='\')
            break;
            printf("%c",a[i]);
        }
        printf("%c\n",a[i]);
    }
}
