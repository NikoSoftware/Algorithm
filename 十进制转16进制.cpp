#include<stdio.h>
int main()
{
    int n,m,i=0;
    char a[100],h;
    while(scanf("%d",&n)!=EOF)
    {
        while(n!=0)
        {
            h=n%16;
            if(h>9)
            {
                h=(h-10)+'A';
            }
            else
            h+='0';
            n/=16;
            a[i++]=h;
        }
        while(i--)
        {
            printf("%c",a[i]);
        }
        printf("\n");
    }
}
