#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    char a[10];
    gets(a);
    n=strlen(a);
    printf("����%dλ��.\n",n);
    printf("ÿһλ��:\n");
    for(i=0;i<n;i++)
    {
       printf("%c ",a[i]);
    }
    printf("\n�������:\n");
    for(i=n-1;i>=0;i--)
    printf("%c",a[i]);
}

