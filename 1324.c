#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,j,sum;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum=0;
        for(j=1;j<i;j++)
        {
            if(i%j==0)
            {
                sum+=j;
            }
        }
        if(i==sum)
        {
            printf("%d its factors are ",i);
            for(j=1;j<i;j++)
            if(i%j==0)
            printf("%d ",j);
            printf("\n");
        }
    }


    return 0;
}
