#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char a[100],*p;

    while(gets(a)!=NULL)
    {
       int i,n, sum=0;
        p=a;
        n=strlen(a);
        while(*p!='\0')
        {
           sum=sum*10+(*p-'0');
            //sum+=(*p-48)*pow(10.0,n-i-1);
            p++;
            i++;
        }
        printf("%d\n",sum);
    }

}

