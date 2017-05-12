#include<stdio.h>
#include<string.h>
unsigned long long a[10000000],j,i,m,n;
int main()
{
    int z,sum;
    while(scanf("%lld%lld",&n,&m)!=EOF)
          {
              if(n==m)
              {
                  for(i=2;i<m;i++)
                  {
                      if(m%i==0)
                      {
                          sum=1;
                          break;
                      }
                  }
                  if(sum==0)
                  printf("-1\n");
                  else
                  printf("%lld\n",n);
              }
              else
              {
                  z=0;
              if(n<2)
              n=2;
           for(i=n;i<m;i++)
           {
               sum=0;
               for(j=2;j<i;j++)
               {
                   if(i%j==0)
               {
                  sum=1;
                  break;
               }
               }
               if(sum==0)
               {
                   a[z]=i;
                   z++;
               }

           }
           if(z==0)
           {
               printf("-1\n");
           }
           else
          {
           printf("%lld",a[0]);
              for(i=1;i<z;i++)

           {
               printf(" %lld",a[i]);

          }
           printf("\n");
          }

          }
          }
}
