#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

void xier(int *a,int n,int z)
{
    if(n==1)
        return;
    int i=0;
    while(i<z)
    {
        while(i<n)
        {
            if(a[i]>a[i+n])
            {
                int tem=a[i];
                a[i]=a[i+n];
                a[i+n]=tem;
            }
            i++;
        }
        //printf("%d\n",i);
        i+=n;
    }
        for(int i=0; i<z; i++)
        printf("%d ",a[i]);
        printf("\n");
    n=(n+1)/2;
    xier(a,n,z);
}

int main()
{
    int a[100];
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    xier(a,(n+1)/2,n);
    for(int i=0; i<n-1; i++)
    {
        if(a[i]>a[i+1])
        {
            int tem=a[i];
            a[i]=a[i+1];
            a[i+1]=tem;
        }
    }
    //sort(a,a+n-1);
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
        printf("\n");

    return 0;
}
