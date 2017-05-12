#include<stdio.h>
#include<string.h>
int chu(int a[],int n,int m)
{
    int i,j,z=0,p,k=1;
    memset(a,0,n);
    a[0]=1;
    while(1)
    {
        for(i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(k%m==0)
                {
                    a[i]=0;
                    p=i;
                    z++;
                }
                k++;
            }
        }
        if(z==n)
        break;
    }
    return p;
}
int main()
{
    int a[1000],n;
    scanf("%d",&n);
    printf("%d\n",chu(a,n,3));
}
