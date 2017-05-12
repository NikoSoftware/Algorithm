#include<stdio.h>
#include<string.h>
#define Max 1000000
int num[Max];
int main()
{
    int n,a,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        memset(num,0,sizeof(num));
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            num[a]++;
        }
        for(i=0;i<Max;i++)
            for(j=0;j<num[i];j++)
            printf("%d ",i);
            printf("\n");
    }
    return 0;
}
