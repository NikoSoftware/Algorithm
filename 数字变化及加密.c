#include<stdio.h>
int  main()
{
char a[100];
int i;
while(scanf("%s",a)!=EOF)
{
	for(i=0;a[i];i++)
   {
    if(a[i]>='a'&&a[i]<='y')
     a[i]+=1£»
else
if(a[i]=='z')
a[i]='a';
   }
	printf("%s ",a);
}

return 0;
}
