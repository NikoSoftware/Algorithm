#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,sum=0;
   char a[400]={'i'},b[400]={'i'};
   while(scanf("%s",a)!=EOF)
   {
       n=strlen(a);
       for(i=0;i<n;i++)
       {
           b[n-i-1]=a[i];
       }
	   for(i=0;i<n;i++)
       {
		   if(b[i]!=a[i])
              sum=1;
	   }
	   if(sum==0)
           printf("Y");
       else
       printf("N");
   printf("\n");
   }
   return 0;
}
