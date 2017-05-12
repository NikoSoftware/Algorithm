#include<stdio.h>
#include<string.h>
int main()
{
    int i,n;
    char str[1000];
    gets(str);
    n=strlen(str);
    for(i=0;i<n;i++)
    {
        if(str[i]>='A'&&str[i]<='z')
        printf("%c",str[i]);
    }
    return 0;
}
