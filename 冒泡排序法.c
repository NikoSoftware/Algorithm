#include<stdio.h>
int main()
{
    int str[6],i,j,tem;
    for(i=0;i<=5;i++)
    scanf("%d",&str[i]);
    for(i=0;i<=5;i++)
  {
        for(j=0;j<=5-i;j++)
      {
          if(str[j]<str[j+1])
    {

       tem=str[j];
        str[j]=str[j+1];
        str[j+1]=tem;
    }

    }
  }
    for(i=0;i<6;i++)
    {
        printf("%d ",str[i]);
    }
}
