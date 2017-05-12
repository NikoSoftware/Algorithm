#include<stdio.h>
int a[1000000],n,i;
void paixu(int a[],int low,int high)
{
    int i=low,j=high,mid=0;
    if(low<high)
    {
        mid=a[i];
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
        paixu(a,low,i-1);
        paixu(a,i+1,high);
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        paixu(a,0,n-1);
        for(i=0;i<n-1;i++)
        printf("%d ",a[i]);
        printf("%d",a[n-1]);
    }
}
