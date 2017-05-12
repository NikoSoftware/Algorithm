#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,k,aa,r,aaa;
    char a[100],b[1000];
    int i,j,sum;
    scanf("%d",&n);
    for(aaa=0;aaa<n;aaa++)
    {
        sum=0;
        scanf("%d%d",&m,&k);
        for(i=0;i<m;i++)
        {
            scanf("%s",a);
            b[sum]=',';
            for(j=0;j<strlen(a);j++)
            {
                b[++sum]=a[j];
            }
            sum++;
        }
        int sun,mm;
        for(mm=0;mm<k;mm++)
        {
            scanf("%d",&r);
            sun=0;
            for(i=0;i<sum;i++)
            {
                if(b[i]==',')
                    sun++;
                if(sun==r)
                {
                    for(j=i+1;j<sum;j++)
                    {
                        if(b[j]==',')
                        break;
                        printf("%c",b[j]);
                    }
                    printf("\n");
                    break;
                }
            }
        }
    }


    return 0;
}
