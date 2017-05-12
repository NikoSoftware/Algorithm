#include<stdio.h>
#include<string.h>
bool v[10000000];
void prin()
{
    int i,j,n=10000000;
    for(i=2;i<=n;i++)
    {
        if(!v[i])
        {
            for(j=i+i;j<=n;j+=i)
            v[j]=1;
        }
    }
}
int main()
{
     int n,i,j,flag=0;
     scanf("%d",&n);
     prin();
     if(i<=3)
     {
         printf("No triple\n");
         flag=1;
     }
     for(i=3;i<n;i++)
     {
         if(v[i]==0&&v[i-2]==0&&v[i+2]==0)
         {
             printf("%d %d %d\n",i-2,i,i+2);
             flag=1;
         }
     }
     if(flag==0)
     printf("No triple\n");
    return 0;
}
