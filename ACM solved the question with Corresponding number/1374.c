#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,sum;
    for(i=1;i<=1000;i++)
    {
        sum=0;
        for(j=1;j<i;j++)
        {
            if(i%j==0)
            sum+=j;
        }
        if(i==sum)
        {
            j=i;
            printf("%d=%d",i,1);
          for(j=2;j<i;j++)
          {
              if(i%j==0)
              printf("+%d",j);
          }
          printf("\n");
        }
    }
    return 0;
}
