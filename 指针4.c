#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,a,m;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&op);
            if(op==1)//在第inex位置插入val
            {
                scanf("%d%d",&intdex,&val);
                for(i=n;i>index;i++)
                a[i]=a[i-1];
                n++;
            }
            else if(op==2)
            {
                scanf("%d",&index);
                for(i=intdex;i<n-1;i++)
                {
                    a[i]=a[i+1];
                    n--;
                }
            }
            else
            {
                printf("%d",a[0]);
                for(i=0;i<n;i++)
                {
                    printf(" %d",a[i]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
