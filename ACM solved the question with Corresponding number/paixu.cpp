#include<stdio.h>
#include <algorithm>
using namespace std;
int b[1000];

void quicksort(int *a,int low,int high)
{
    int i=low,j=high,tem;
    if(low<high)
    {
        int mid=a[i];
        int mid1=b[i];
        while(i<j)
        {
            while(i<j&&mid<=a[j])
                j--;
            a[i]=a[j];
            tem=b[i];
            b[i]=b[j];
            b[j]=tem;
            while(i<j&&mid>=a[i])
                i++;
            a[j]=a[i];
            tem=b[i];
            b[i]=b[j];
            b[j]=tem;
        }
        a[i]=mid;
        quicksort(a,low,i-1);
        quicksort(a,j+1,high);
    }
}
int main()
{
    int i,n=24,a[1000];
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        b[i]=i;
    }
    quicksort(a,0,n-1);
    for(i=0; i<n; i++)
        printf("时间%d，人数%d\n",b[i],a[i]);
    return 0;
}
