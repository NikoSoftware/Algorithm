#include<stdio.h>
int main()
{
    int n,m,i,j,sum,a[100],vis[100],z,r,k;
    scanf("%d",&n);
    while(n--)
    {
        sum=0;
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
            vis[i]=0;
        }
        if(sum%4!=0)
        {
            printf("no\n");
            continue;
        }
        k=sum/4;
        printf("%d\n",k);
        for(j=0;j<m;j++)
        {
            int flag=0;
            if(a[j]==k||a[j]!=0)
            {
                flag=1;
                continue;
            }
            for(r=j+1;r<m;r++)
            {
                if(a[r]!=1&&a[j]+a[r]==k)
                {
                    flag==1;
                    vis[r]=1;
                    continue;
                }
            }
            if(flag==0)
            printf("no\n");
            else
            printf("yes\n");
        }


    }
    return 0;
}
