#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j=0;
    char a[1000],b[1000];
    gets(a);
    n=strlen(a);
    for(i=0;i<n;i++)
    {
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
        {
            b[j]=a[i];
            j++;
        }
    }
    printf("%s",b);
}



