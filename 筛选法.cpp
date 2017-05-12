#include<stdio.h>
#include<string.h>
bool v[100000];
void prin()
{
    int i,j,n=100000;
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
    int i,k=0,n=100000;
    prin();
    for(i=2;i<=n;i++)
    {
        if(!v[i])
        {
            printf("%d ",i);
           k++;
        }
    }
    printf("\n%d\n",k);
    return 0;
}




