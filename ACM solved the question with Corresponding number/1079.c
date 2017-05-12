#include<stdio.h>
#include<math.h>
int main()
{
    int a[100],i,j,n,empty;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(abs(a[i])<abs(a[j]))
                {
                    empty=a[j];
                    a[j]=a[i];
                    a[i]=empty;
                }
            }
        }
        for(i=0;i<n-1;i++)
        printf("%d ",a[i]);
        printf("%d\n",a[i]);
    }
    return 0;
}
