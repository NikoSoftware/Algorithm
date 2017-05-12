#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    char str[20];
    gets(str);
    n=strlen(str);
    printf("%d\n",n);
    for(i=0;i<n-1;i++)
        printf("%c ",str[i]);
        printf("%c\n",str[n-1]);
        for(i=n-1;i>=0;i--)
        printf("%c",str[i]);
}
