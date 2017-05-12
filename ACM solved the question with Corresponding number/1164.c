#include<stdio.h>
#include<string.h>
int main()
{
    int a[100],n,i;
    char str[1000];
    for(i=0;i<26;i++)
    a[i]=0;
    while(gets(str))
    {
        n=strlen(str);
        for(i=0;i<n;i++)
        {
             if(str[i]>='a'&&str[i]<='z')
             a[str[i]-'a']++;
             else if(str[i]=='#')
             break;
        }
        if(str[n-1]=='#')
        break;
    }
     for(i=0;i<26;i++)
        printf("%c %d\n",'a'+i,a[i]);
    return 0;
}
