#include<stdio.h>
int main()
{
    int a[10],tem,j,i;
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<9;i++)
    {
        for(j=i+1;j<10;j++)
        {
        if(a[i]<a[j])
        {
            tem=a[i];
            a[i]=a[j];
            a[j]=tem;
        }
    }
    }
    for(i=0;i<9;i++)
    printf("%d ",a[i]);
    printf("%d\n",a[9]);
}






