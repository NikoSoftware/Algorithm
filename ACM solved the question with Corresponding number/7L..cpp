#include<stdio.h>
int main()
{
    int n,i,j,a,str[10000],stt[10000],sum;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        sum=0;
        scanf("%d",&a);
        scanf("%d",&str[0]);
        for(j=1;j<a;j++)
        {
            scanf("%d",&str[j]);
            if(str[j]!=str[0]+j)
            stt[sum++]=j+1;
        }
        printf("Case #%d:",i+1);
        for(j=0;j<sum;j++)
        printf(" %d",stt[j]);
        printf("\n");
    }
    return 0;
}
