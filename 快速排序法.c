#include<stdio.h>
int data[100005];
void quicksort(int data[],int low,int high)
{
    int i=low,j=high;//����ָ�룬low �ĳ�ʼֵΪ0��high�ĳ�ʼֵΪ���鳤�ȼ�һ
    int mid=0;//�ؼ���
    if(low<high)
    {
        mid=data[i];//�������һ��Ԫ����Ϊ�ؼ���
        while(i<j)//ѭ������
        {
            while(i<j&&mid<=data[j])//��ǰ���󣬱ȹؼ��ִ����ǰ�ƶ����ҽ�������ĸ�ֵ����
                j--;
            data[i]=data[j];//����ǰ�Ĵ��Ԫ�ظ�ֵ��low���ڵ�λ�ã�Ҳ���Ǹո��ᵽ�Ŀ�λ
            while(i<j&&mid>=data[i])//��ǰ���󣬱ȹؼ��ֵ�С�ľ�����ƶ����ҽ�������Ĳ���
                i++;
            data[j]=data[i];
        }

        data[i]=mid;//��i==jʱ����һ��������������ؼ��ֵ�ֵ����i���ڵ�λ��
        quicksort(data,low,i-1);//�Աȹؼ���С��Ԫ�ؽ�������
        quicksort(data,i+1,high);//�Աȹؼ��ִ�Ľ�������
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
