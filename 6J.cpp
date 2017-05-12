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
int erfen(int *b,int data, int n,int m)
{
    int i=0,j;
    if(m==0)
        return b[0];
    if(data>b[m-1])
    {
        printf("Impossible\n");
        return -1;
    }
    if(data==b[(n+m)/2])
    {
        return data;
    }
    else if(data>b[(n+m)/2])
        erfen(b,data,(n+m)/2,m);
    else if(data<b[(n+m)/2+1])
    {
        return b[(n+m)/2+1];
    }
    else
        erfen(b,data,0,(n+m)/2);
}
int main()
{
    int n,m,a[1000],b[1000],i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int k,sum=0;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(i=0; i<m; i++)
            scanf("%d",&b[i]);
         if(n>m)
         {
             printf("Impossible\n");
             continue;
         }
        quicksort(b,0,m-1);
        for(i=0; i<n; i++)
        {
            k=erfen(b,a[i],0,m);
            if(k==-1)
                break;
                printf("~ %d ~",k);
            sum+=k;
        }
        if(k==-1)
            continue;
        else
            printf("%d\n",sum);
    }

    return 0;
}
