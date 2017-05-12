#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    char a[100],b,*p;
    while(scanf("%c",&b)!=EOF)
    {
        getchar();
        gets(a);
        n=strlen(a);
        for(i=0;i<n;i++)
        {
            if(a[i]==b)
            continue;
            printf("%c",a[i]);
        }
        printf("\n");
    }
}
