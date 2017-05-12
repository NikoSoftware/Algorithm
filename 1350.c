#include<stdio.h>
int main()
{
    int i,j,z,sum[10]={0,0,0};
    char a[100],tem;
    for(i=0;i<3;i++)
    for(j=i*3;j<(i+1)*3;j++)
    scanf("%c",&a[j]);
    for(i=0;i<3;i++)
    for(j=i*3;j<(i+1)*3;j++)
    {
        sum[i]+=a[j];
    }
    for(i=0;i<2;i++)
    for(j=i+1;j<3;j++)
    {
        if(sum[i]>sum[j])
        {
            tem=a[i];
            a[i]=a[j];
            a[j]=tem;
            tem=a[i+1];
            a[i+1]=a[j+1];
            a[j+1]=tem;
            tem=a[i+2];
            a[i+2]=a[j+2];
            a[j+2]=tem;
        }
    }
    for(i=0;i<3;i++)
    {
    for(j=i*3;j<(i+1)*3;j++)
    printf("%c",a[j]);
    printf("\n");
    }
    return 0;
}
