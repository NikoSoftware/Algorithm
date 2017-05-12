#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,z,i,j;
    char a[1000];
    while(gets(a)!=NULL)
    {
        scanf("%d",&z);
        for(j=0;j<z;j++)
        {
        scanf("%d%d",&n,&m);
        for(i=n;i<n+m;i++)
       {
           printf("%c",a[i]);
       }
       printf("\n");
        }
    }
}

