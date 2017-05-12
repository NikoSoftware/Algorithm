#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    char a[200];
    while(scanf("%s",a)!=EOF)
    {
        for(i=0;a[i]!='\0';i++)
       {

       switch(a[i])
       {
       case'1':
       a[i]='0';
       break;
       case'0':
       a[i]='1';
       break;
       }
}
printf("%s\n",a);
}
}
