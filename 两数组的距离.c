#include<stdio.h>
int main()
{
    int a[1000],b[1000],i,j,n,m,num;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int diff=1000000000;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(j=0; j<m; j++)
            scanf("%d",&b[j]);
            //num=0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                num=a[i]-b[j];
                if(num<0)
                    num=-num;
                if(diff>num)
                    diff=num;
            }
        }
        printf("%d\n",diff);
    }
    return 0;
}
