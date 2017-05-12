#include<stdio.h>
#include<string.h>

int a[10000],z=10000;
void prime()
{
    int i,j;
    memset(a,0,sizeof(a));
    a[0]=a[1]=1;
    for(i=2;i<z;i++)
        if(a[i]==0)
            for(j=2;i*j<z;j++)
                a[i*j]=1;

}
int main()
{
    int n;
    prime();
    while(scanf("%d",&n)!=EOF)
    {
    if(a[n]==0)
    printf("YES");
    else
    printf("NO");
    }
    return 0;
}
