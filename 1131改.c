#include<stdio.h>
#include<string.h>
int main()
{
    int a[100],b[100],n,i,j,mid;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       int z=0;
        for(j=0;j<9;j++)
        scanf("%d",&a[j]);
        mid=a[0];
        for(j=8;j>0;j--)
        {
            if(mid>a[j])
            {
                b[z]=a[j];
                z++;
                a[j]=-1;
            }
        }
        for(j=0;j<9;j++)
        {
            if(a[j]!=-1)
            {
                b[z]=a[j];
                z++;
            }
        }
        for(j=0;j<8;j++)
        printf("%d ",b[j]);
        printf("%d\n",b[8]);
    }
}
