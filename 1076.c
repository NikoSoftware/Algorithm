#include<stdio.h>
int main()
{
    int x,y,i,sum=0;
    scanf("%d%d",&x,&y);
    for(i=x;i<=y;i++)
    {
        if(i%3==1&&i%5==3)
        sum+=i;
    }
    printf("%d",sum);
    return 0;
}
