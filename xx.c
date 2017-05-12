#include<stdio.h>
int main()
{
    int n,m,str[100],sum;
    int con,i;
    scanf("%d",&con);
    while(con--)
    {
        sum=0;
        scanf("%d",&n);
        for(m=0;m<n;m++)
        scanf("%d",&str[m]);
        for(i=0;i<n;i++)
        sum=sum+str[i];
        printf("%d\n",sum);
    }
}
