#include<stdio.h>
#include<string.h>
int main()
{
   int n,str[100],i,j,f,z=0,tem;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       scanf("%d",&str[i]);
   }
   for(i=0;i<n-1-z;i++)
   {
       for(j=i+1;j<n-z;j++)
       {
           if(str[i]==str[j])
           {
               z++;
               for(f=j;f<n-1;f++)
               str[f]=str[f+1];
           }
       }
   }
   for(i=0;i<n-z-1;i++)
   {
       for(j=i+1;j<n-z;j++)
       {
           if(str[i]>str[j])
           {
               tem=str[j];
               str[j]=str[i];
               str[i]=tem;
           }
       }
   }
   printf("%d\n",n-z);
   for(i=0;i<n-z-1;i++)
   {
       printf("%d ",str[i]);
   }
   printf("%d",str[n-z-1]);
    return 0;
}
