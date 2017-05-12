#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,flag,j;
    scanf("%d",&n);
    printf("%d ",2);
    for(i=3;i<=n;i++)
    {
        flag=0;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                flag=1;
            }
        }
        if(flag==0)
        printf("%d ",i);
    }

    return 0;
}
