#include<stdio.h>
int main()
{
    int str[10],i,j;
    for(i=0;i<10;i++)
    scanf("%d",&str[i]);
    for(j=9;j>0;j--)
    {
        printf("%d ",str[j]);
    }
    printf("%d",str[0]);
    return 0;
}
