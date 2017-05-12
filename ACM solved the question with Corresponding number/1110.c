#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    char a[1000],b[1000];
    gets(a);
    n=strlen(a);
    for(i=0;i<n;i++)
    b[i]=a[n-i-1];
    b[n]='\0';
    if(strcmp(a,b)==0)
    printf("Y\n");
    else
    printf("N\n");

}
