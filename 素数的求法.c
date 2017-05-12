


//ÐÂËã·¨
#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {

        for(i=2;i<=n;i++)
        {
            int sum=0;
            for(j=2;j<=sqrt(i);j++)
            {
                if(i%j==0)
                sum=1;
            }
            if(sum==0)
            printf("%d ",i);
        }
    }
}
