#include<stdio.h>
int main()
{
    int n,i,z;
   while(scanf("%d",&n)!=EOF)
   {
       int sum=0;
       for(i=1;i<=n;i++)
       {
           if(i%2==0)
           z=0;
           else
           z=i;
           sum+=z;
       }
       printf("%d\n",sum);
   }
   return 0;
}
