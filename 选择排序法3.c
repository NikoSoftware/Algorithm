#include<stdio.h>
int main()
{
    int a,i,j,str[10],tem;
    for(a=0;a<10;a++)
    {
     scanf("%d",&str[a]);
    }
    for(i=0;i<9;i++)
    {
        for(j=i;j<10;j++)
        {
            if(str[i]<str[j])
            {
                tem=str[i];
            str[i]=str[j];
            str[j]=tem;
            }
        }

    }
    for(i=0;i<10;i++)
    printf("%d ",str[i]);
}
