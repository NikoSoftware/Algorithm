#include<stdio.h>
#include<string.h>
int main()
{
    int a[100],i,sum=0,count=0;
    float ave;
    for(i=0;i<20;i++)
    scanf("%d",&a[i]);
    for(i=0;i<20;i++)
    {
        if(a[i]>=0)
        sum+=a[i];
        else
        count++;
    }
    printf("%d\n",count);
    printf("%.2f\n",sum*1.0/(20-count));

}
