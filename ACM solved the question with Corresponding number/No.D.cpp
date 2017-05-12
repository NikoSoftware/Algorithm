#include <stdio.h>
int main()
{
    int i,j,n,max,a[1000],data[1000];
    while(scanf("%d",&n)&&n!=0)
    {
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(i=0; i<n; i++)
        {
            data[i]=a[i];
            for(j=0; j<=i-1; j++)
            {
                if(a[j]<a[i]&&data[j]+a[i]>data[i])
                    data[i]=data[j]+a[i];
            }
        }
        max=data[0];
        for(i=1; i<n; i++)
        {
            if(data[i]>max)
                max=data[i];
        }
        printf("%d\n",max);
    }
    return 0;
}
