#include<stdio.h>
int main()
{
    int i,n,a,sum;
   while(scanf("%d",&n)!=EOF)
  {

   sum=0;
   for(i=0;i<n;i++)
   {
       scanf("%d",&a);
       sum+=a;
   }

  }
   printf("%d",sum);
   return 0;
}
