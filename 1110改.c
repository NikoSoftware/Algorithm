#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000],sum=0;
    int n,i;
    gets(a);
    n=strlen(a);
    for(i=0;i<n;i++)
    {
        if(a[n-i-1]!=a[i])
       {
        sum=1;
        break;
       }
    }
    if(sum==0)
    printf("Y\n");
    else
    printf("N\n");
}
