#include<stdio.h>
int  main()
{
char a[80];
int i;
while(scanf("%s",a)!=EOF)
{
for(i=0;a[i];i++)
   {
    if(a[i]>='a'&&a[i]<='z')
     a[i]-=32;

     }
printf("%s\n",a);
}

return 0;
}
