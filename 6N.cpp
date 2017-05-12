#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,k,i,j,x,y,a[10000];
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {

        scanf("%d%d",&n,&m);
        int cnt=0,sum=0,z=m;
        while(m--)
        {
            scanf("%d",&a[cnt++]);
        }
        printf("Case #%d:\n",i+1);
        for(j=0;j<z;j++)
        {
            sum+=a[j];
            if((sum/n)%4==0)
            {
                printf("%d %d\n",sum%n,0);
            }
            else
            if((sum/n)%4==1)
            {
                printf("%d %d\n",n,sum%n);
            }
            else
            if((sum/n)%4==2)
            {
                printf("%d %d\n",n-sum%n,n);
            }
            else
            printf("%d %d\n",0,n-sum%n);
        }
    }
}
