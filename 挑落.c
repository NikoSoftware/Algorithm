#include<stdio.h>
int main()
{
    int i,j,a[100],tab;
    for(i=0;i<4;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<4-1;i++)
    {
        for(j=i+1;j<4;j++)
        {
            if(a[i]>a[j])
            {tab=a[i];
            a[i]=a[i+1];
            a[i+1]=tab;
            }
        }
    }
    for(i=0;i<4;i++)
    printf("%d ",a[i]);

    return 0;
}
