#include<stdio.h>
#include<math.h>
int main()
{
    int i,sum=0,j,n,m,flag;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        m=i;
        flag=0;
        while(m)
        {
           if(m%10==7)
           {
               sum++;
               flag=1;
               break;
           }
           m=m/10;
        }
        if(i%7==0&&flag==0)
        sum++;
    }
    printf("%d\n",sum);
}
