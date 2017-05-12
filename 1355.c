#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,i,f;
    char a[100];
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    scanf("%c",&a[i]);
    scanf("%d",&m);
    for(i=m-1;i<n;i++)
    printf("%c",a[i]);
}
