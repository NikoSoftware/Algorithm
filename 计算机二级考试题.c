#include<stdio.h>
int main()
{
    int str[10],i,j,sum=0,average,amount=0;
    for(i=0;i<10;i++)
    {
        scanf("%d",&str[i]);
    sum+=str[i];
    }
    average=sum/10;
    for(i=0;i<10;i++)
    {
        if(average<str[i])
    amount++;
    }
    printf("%d\n",amount);
    return 0;

}
