#include<stdio.h>
bool v[1000000];
void prin()
{
    int i,j,n=1000000;
    v[0]=v[1]=1;
    for(i=2;i<=n;i++)
    {
        if(!v[i])
        {
            for(j=i+i;j<=n;j+=i)
            v[j]=1;
        }
    }
}
int main()
{
    int n,i;
    prin();
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        break;
        int flag=0;
        for(i=1;i<=n;i++)
        {
            if(v[i]==0)
            {
                if(v[n-i]==0)
                {
                    flag=1;
                    printf("%d = %d + %d\n",n,i,n-i);
                    break;
                }
            }
        }
        if(flag==0)
        printf("Goldbach's conjecture is wrong.\n");

    }
    return 0;
}
