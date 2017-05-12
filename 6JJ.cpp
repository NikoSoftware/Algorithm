#include<stdio.h>
#include<string.h>
int vis[1000],a[1000],b[1000];
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
        int sum=0,flag=0;
        for(i=0; i<n; i++)
            scanf("%d",&b[i]);
        for(i=0; i<m; i++)
        {
            scanf("%d",&a[i]);
            vis[i]=0;
        }
        if(n>m)
        {
            printf("Impossible\n");
            continue;
        }
        quicksort(a,0,m-1);

        for(i=0; i<n; i++)
        {
            for(j=0; j<=m; j++)
            {
                if(j==m)
                {
                    printf("Impossible\n");
                    flag=1;
                    break;
                }
                if(b[i]<=a[j]&&vis[j]==0)
                {
                    sum+=a[j];
                    vis[j]=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        if(flag==1)
            continue;
        printf("%d\n",sum);
    }
}
