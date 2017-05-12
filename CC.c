#include<stdio.h>
int main()
{
    int n,m,str[100];
    int con;
    scanf("%d",&con);
    while(con--)
    {
        scanf("%d",&n);
        for(int m=0;m<n;m++)
        scanf("%d",str[m]);
        for(i=0;i<n;i++)
        sum=sum+str[i];
        printf("%d",sum);
    }
}
