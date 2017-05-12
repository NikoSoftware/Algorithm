#include<stdio.h>
#include<string.h>
#include<math.h>
int n,data[100000];

void sx()
{
    int i;
    data[1]=1;
    for( i=2;i<4000;i++)
    {
        if(!data[i])
        {
            int j;
            for( j=i*2;j<4000;j+=i)
            {
                data[j]=1;
            }
        }
    }
}


int main()
{
    int m;
    memset(data,0,sizeof(data));
    sx();
   while(scanf("%d",&n)!=EOF)
   {
       m=0;
       int i;
       for(i=2;i<=n/2;i++)
       {
           if(data[i]==0&&data[n-i]==0)
           {
                   m++;

           }
       }
       printf("%d\n",m);

   }
    return 0;
}
