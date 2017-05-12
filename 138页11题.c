#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    char a[10];
    gets(a);
    n=strlen(a);
    printf("它是%d位数.\n",n);
    printf("每一位数:\n");
    for(i=0;i<n;i++)
    {
       printf("%c ",a[i]);
    }
    printf("\n逆序输出:\n");
    for(i=n-1;i>=0;i--)
    printf("%c",a[i]);
}

