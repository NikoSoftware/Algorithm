#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000],sum,n,i;
    printf("请输入QQ：");
    while(scanf("%s",a)!=EOF)
    {
        sum=0;
        n=strlen(a);
        for(i=0; i<n; i++)
        {
            sum+=a[i]-'0';
        }
        printf("QQ号之和为：%d\n",sum);
    }
    return 0;
}
