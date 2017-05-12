#include<stdio.h>
int main()
{
    int str[10],i,j,tem;
    for(i=0;i<10;i++)
    scanf("%d",&str[i]);
    for(i=0;i<9;i++)
    {
        for(j=0;j<9-i;j++)
        {
            if(str[j]>str[j+1])
            {
                tem=str[j];
                str[j]=str[j+1];
                str[j+1]=tem;
            }
        }
    }
    for(i=0;i<10;i++)
    printf("%d",str[i]);
    return 0;
}
