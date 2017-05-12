#include<stdio.h>
int a[1000]={20,17,34,8,29,33,7,9,21,6};
void quicksort(int *a,int low,int high)
{
    int i=low,j=high;
    int mid=a[i];
    if(i<j)
    {
        while(i<j)
        {
            while(i<j&&mid>=a[j])
            j--;
            a[i]=a[j];
            while(j<i&&mid<=a[i])
            i++;
            a[j]=a[i];
        }
        a[i]=mid;
        quicksort(a,low,i-1);
        quicksort(a,i+1,high);
    }

}
int main()
{

    quicksort(a,0,9);
    for(int i=0;i<10;i++)
    printf("%d ",a[i]);
    return 0;
}
