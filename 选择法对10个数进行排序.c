#include<stdio.h>
int main()
{
    int str[10],i,tem,j;
    for(i=0;i<10;i++)
    scanf("%d",&str[i]);
    for(i=0;i<9;i++)
   {
       for(j=i;j<9;j++)
       {

       if(str[i]>str[j+1])
    {
        tem=str[j+1];
    str[j+1]=str[i];
    str[i]=tem;
    }
   }
      printf("%d\n",str[i]);
   }
   return 0;
}



