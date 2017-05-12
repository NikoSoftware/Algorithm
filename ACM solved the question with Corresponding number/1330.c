#include<stdio.h>
#include<string.h>
int main()
{
    int a[100],i,j,tem;
    for(i=0;i<10;i++)
    scanf("%d",&a[i]);
    for(i=0;i<9;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(a[i]>a[j])
            {
                tem=a[i];
                a[i]=a[j];
                a[j]=tem;
            }
        }
    }
    for(i=0;i<10;i++)
    printf("%d\n",a[i]);
}
