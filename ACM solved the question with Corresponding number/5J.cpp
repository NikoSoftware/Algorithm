#include<stdio.h>
#include<string.h>
int a[10000],b[10000];
bool c[10000];
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
    int n,m,i,j;
   while(scanf("%d%d",&n,&m)!=EOF)
   {
       memset(c,0,sizeof(c));
       for(i=0;i<n;i++)
       scanf("%d",&a[i]);
       for(i=0;i<m;i++)
       {
           scanf("%d",&b[i]);
           c[b[i]]=1;
       }
       quicksort(a,0,n-1);
       quicksort(b,0,m-1);
       for(i=0;i<m;i++)
       {
           if(a[n-1]<b[i])
           {
               int k=i;
               break;
           }
       }
       while(n-1)
       {
           if(a[n-1]<=b[k])
           {
               if(a[n-1]>=b[k-1])
               sum+=b[k];
               c[b[k]=0;
           }

       }




   }

    return 0;
}
