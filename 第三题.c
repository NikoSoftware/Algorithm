#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000];
    int n,i;
    gets(a);
    n=strlen(a);
    for(i=0;i<n;i++)
    {
        if(a[i]>='a'&&a[i]<='y')
            a[i]++;
        else if(a[i]=='z')
            a[i]='a';
    }
    printf("%s",a);
    return 0;
}
