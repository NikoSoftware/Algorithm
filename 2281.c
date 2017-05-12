#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,k,f,flag=0,i;
    char a[1000];
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<k;i++)
    {
    gets(a);
    f=strlen(a);
    if(n>=f*m)
    flag=1;
    }
    if(flag==1)
    printf("YES\n");
    else
    printf("NO\n");
}
