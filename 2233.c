//���ַ�������
#include<stdio.h>
#include<string.h>
int main()
{
    int a[1000],n,i,m,z,sum,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        j=0;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        while(scanf("%d",&z)!=EOF)
        {
            sum=0;
            j++;
            if(j>m)
            break;
            for(i=0;i<n;i++)
            {
                if(z==a[i])
                {
                    sum=1;
                    printf("%d\n",i);
                break;
                }
            }
             if(sum==0)
            printf("-1\n");
        }
    }
}