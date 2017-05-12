#include<stdio.h>
#include<string.h>

void quicksort(int *a,int low,int high)
{
    int i=low,j=high;
    if(low<high)
    {
        int mid=a[i];
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
        quicksort(a,low,i-1);
        quicksort(a,j+1,high);
    }
}
int main()
{
    int a[1000],n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
    return 0;
}
