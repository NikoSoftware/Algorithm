#include<stdio.h>
#include<string.h>
#define Max 10000
int ispri[Max];
void prime()
{
    int i,j;
    memset(ispri,0,sizeof(ispri));
    ispri[1]=1;
    ispri[0]=1;
    for(i=2;i<Max;i++)
       if(ispri[i]==0)
       for(j=2;i*j<Max;j++)
       ispri[i*j]=1;
}
int main()
{
    int n,i,sum;
    void prime();
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        for(i=2;i<n;i++)
        {
            if(ispri[i]==0&&(ispri[n-i]==0))
            {
                sum=1;
            }
        }
        if(sum==1)
        printf("Yes\n");
        else
        printf("No\n");
    }
}


