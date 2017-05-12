#include<stdio.h>
#include<string.h>
int main()
{
    int i,n;
    char str[1000]={0};
     gets(str);
    n=strlen(str);
    for(i=0;i<n;i++)
    {
        if(str[i]=='z')
        str[i]='a';
        else if(str[i]=='Z')
        str[i]='A';
        else if(str[i]>='a'&&str[i]<'z'||(str[i]>='A'&&str[i]<'Z'))
        str[i]++;

    }
     printf("%s",str);
}
