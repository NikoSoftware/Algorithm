#include<stdio.h>
#include<string.h>
int a[100000];
void paixu(int a[],int low,int high)
{
    int i=low,j=high,mid=0;
    if(low<high)
    {
        mid=a[i];
        while(i!=j)
        {
            while(i<j&&mid>a[j])
            j--;
            if(i<j)
            {
            a[i]=a[j];
            i++;
            }
            while(i<j&&mid<a[i])
            i++;
            if(i<j)
            {
            a[j]=a[i];
            j--;
            }
        }
            a[i]=mid;
    paixu(a,low,i-1);
    paixu(a,i+1,high);
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    paixu(a,0,n-1);
    for(i=0;i<n-1;i++)
    printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
}
