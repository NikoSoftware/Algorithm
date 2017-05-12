#include<stdio.h>
void digui(int a[],int low,int high)
{
    int i=low,j=high,mid=0;
    if(low<high)
    {
        mid=a[0];
        while(i<j)
        {
            while(i<j&&mid<=a[j])
                j--;
            a[i]=a[j];
            while(i<j&&mid>=a[i])
                i++;
            a[j]=a[i];
        }
        a[i]=mid;
    }
}
int main()
{
    int n,i,j,a[100];
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<9; j++)
            scanf("%d", &a[j]);
        digui(a,0,8);
        for(j=0; j<8; j++)
            printf("%d ",a[j]);
        printf("%d\n",a[8]);
    }
}

