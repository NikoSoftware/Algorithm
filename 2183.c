#include<stdio.h>
#include<string.h>
int main()
{
    long sum;
    char a[10000],*p;
    while(scanf("%s",a)!=EOF)
    {
        sum=0;
        p=a;
   while(*p!='\0')
   {
       sum+=*p-48;
       p++;
   }
    printf("%ld\n",sum);
    }
}
