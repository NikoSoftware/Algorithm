#include<stdio.h>
int data[50000],map[50000],n,count;

void two(int a)
{
    if(a>data[count])
    {
        data[++count]=a;
        return ;
    }
    if(a<data[0])
    {
        data[0]=a;
        return ;
    }
    if(a<data[count])
    {
        int l=0,k=count;
        while(l<=k)
        {
            int mid = (l+k)/2;
            if(a>=data[mid]&&a<=data[mid+1])
            {
                data[mid+1]=a;
                return ;
            }
            else if(a>data[mid])
            l=mid+1;
            else
            k=mid-1;
        }
    }

}

void cal()
{
    data[0]=map[0];
    for(int i=1;i<n;i++)
    {
        two(map[i]);
    }

}

int main()
{
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        for(int i=0;i<k;i++)
        {
            count=0;
            scanf("%d",&n);
            for(int j=0;j<n;j++)
            scanf("%d",&map[j]);
            cal();
            //for(int j=0;j<=count;j++)
           // printf("%d ",data[j]);
            printf("%d\n",count+1);
        }
    }

    return 0;
}
