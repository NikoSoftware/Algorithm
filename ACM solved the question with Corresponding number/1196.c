#include<stdio.h>
#include<string.h>
int main()
{
    int a[100],n,i,sum=0;
    scanf("%s",a);
    n=strlen(a);
    for(i=0;i<n-1;i++)
    {
    if(a[i]>a[i+1])
    {
        sum=1;
        break;
    }
    }
    if(sum==1)
    printf("NO\n");
    else
    printf("YES\n");
    return 0;
}
