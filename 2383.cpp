#include<stdio.h>
#include<math.h>
#include<string.h>
int a[100000];
void prime()
{
    int i,j;
    for(i=3;i<10000;i++)
    {
        int flag=0;
    for(j=2;j<=sqrt(i);j++)
    {
        if(i%j==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    a[i]=1;
    }
}

int main()
{
    memset(a,0,sizeof(a));
    prime();
    int i,j,k,n;
    while(scanf("%d",&n)!=EOF)
    {
        int sum=1,flag=0;
        if(a[n]==0)
        printf("%c\n",'?');
        else
        for(i=0;i<100000;i++)
        {
            sum=sum*2;
            if(sum%n==1)
            {
                printf("%d\n",i+1);
                break;
            }
        }
    }
    return 0;
}
