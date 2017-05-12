#include<stdio.h>
int data[100005];
void quicksort(int data[],int low,int high)
{
    int i=low,j=high;//两个指针，low 的初始值为0，high的初始值为数组长度减一
    int mid=0;//关键字
    if(low<high)
    {
        mid=data[i];//将数组第一个元素设为关键字
        while(i<j)//循环条件
        {
            while(i<j&&mid<=data[j])//从前往后，比关键字大的向前移动并且进行下面的赋值操作
                j--;
            data[i]=data[j];//将当前的大的元素赋值给low所在的位置，也就是刚刚提到的空位
            while(i<j&&mid>=data[i])//从前往后，比关键字的小的就向后移动并且进行下面的操作
                i++;
            data[j]=data[i];
        }

        data[i]=mid;//当i==j时，第一趟排序结束，将关键字的值付给i所在的位置
        quicksort(data,low,i-1);//对比关键字小的元素进行排序
        quicksort(data,i+1,high);//对比关键字大的进行排序
    }
}
int main()
{
    int i,j,a[5];
    for(i=0;i<5;i++)
    scanf("%d",&a[i]);
    quicksort(a,0,4);
    for(i=0;i<5;i++)
    printf("%d ",a[i]);
    return 0;
}
/*
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
    for(i=0; i<n; i++)
        scanf("%d",&data[i]);
    quicksort(data,0,n-1);
    for(i=0; i<n-1; i++)
        printf("%d ",data[i]);
    printf("%d\n",data[n-1]);
    }
}
*/
