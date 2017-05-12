#include<stdio.h>
 int main()
 {
     int i,j=0,n;
     scanf("%d",&n);
     int m=n;
     int x[n];
     for(i=0;i<n;i++)
     x[i]=1;
     while(n!=1)
     {
         for(i=0;i<m;i++)
         {
             j=j+x[i];
             if(j==3)
             {
                 x[i]=0;
                 j=0;
                 n--;
             }
         }
     }
     for(i=0;i<m;i++)
     if(x[i]==1)
    printf("%d",i+1);
     return 0；
 }

