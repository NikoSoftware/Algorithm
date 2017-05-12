#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,z,i,sum=0;
    char a[1000],*p;
          gets(a);
        scanf("%d",&z);
    for(i=0;i<z;i++)
    {  ++sum;
        n=0;m=0;
        scanf("%d%d",&n,&m);
        p=a+n;
        while(p!=a+(m+n)&&*p!='\0')
        {
        printf("%c",*p);
        p++;
        }
        printf("\n");
    }

}
