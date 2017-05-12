#include<stdio.h>
void prime(int n);
int main()
{
    int i,n;
    scanf("%d",&n);
    prime(n);

}
void prime(int n)
{
    int i,j,flag=0;
    for(i=2;i<=n;i++)
    {
        flag=0;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
           {
            flag=1;
            continue;
           }
        }
        if(flag==0)
        printf("%d ",i);
    }
}
