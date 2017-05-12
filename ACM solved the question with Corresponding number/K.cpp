#include<stdio.h>
#include<string.h>
int main()
{
    int n,j,falg;
    scanf("%d",&n);
    char a[10],b[10];
    for(j=0;j<10;j++)
            a[j]='0';
    for(j=0;j<10;j++)
            b[j]='0';
    int c[10],i,sum;
    for(i=0;i<n;i++)
    {
        scanf("%s%s",a,b);
        sum=0,falg=0;
        if(strlen(a)>=strlen(b))
        for(j=0;j<strlen(a);j++)
        {
            c[j]=((a[j]-'0')+(b[j]-'0'))%10;
            sum++;
        }
        else
        for(j=0;j<strlen(b);j++)
        {
            c[j]=((a[j]-'0')+(b[j]-'0'))%10;
            sum++;
        }
        printf("Case #%d: \n",i+1);
        for(j=0;j<sum;j++)
        {
            if(c[j]!=0)
            falg=1;
        }
        if(falg==0)
        printf("0\n");
        else
        for(j=0;j<sum;j++)
            printf("%d",c[j]);
        printf("\n");
    }

    return 0;
}
