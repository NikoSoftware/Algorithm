#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    char a[1000];
    scanf("%s",a);
    n=strlen(a);
    printf("%s",a);
    for(i=n-1;i>=0;i--)
    printf("%c",a[i]);
    return 0;
}
