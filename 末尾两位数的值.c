#include<stdio.h>
int main()
{
    int i,j,sum,a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        sum=a*100;
        for(i=1;i<100;i++)
        {
            sum++;
            if(sum%b!=0)
             continue;
             printf("%2d ",i);
        }
        printf("\n");
    }
    return 0;
}
