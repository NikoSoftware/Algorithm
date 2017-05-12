#include<stdio.h>
#include<string.h>
#define Max 10000000
int ispri[Max];
void intprime()
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
    int n;
    int prime();
    while(scanf("%d",&n)!=EOF)
    {
        if(ispri[n]==0)
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}
