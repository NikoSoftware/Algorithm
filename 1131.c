#include<stdio.h>
#include<string.h>
int a[1000];
void paixu(int a[],int low,int high)
{
    int i=low,j=high,mid=0;
    if(low<high)
    {
        mid=a[i];
        while(i<j)
        {
        while(i<j&&mid<a[j])
        j--;
        a[i]=a[j];
        while(i<j&&mid>a[i])
        i++;
        a[j]=a[i];
        }
        a[i]=mid;
    }

}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<9;j++)
            scanf("%d",&a[j]);
            paixu(a,0,8);
        for(j=0;j<8;j++)
        printf("%d ",a[j]);
        printf("%d",a[8]);
    }
   return 0;
}
