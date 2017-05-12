#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    float a[100],Max,Min;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%f",&a[i]);
          Max=Min=a[0];
        for(i=1;i<n;i++)
        {
            if(Max<a[i])
            Max=a[i];
            if(Min>a[i])
            Min=a[i];
        }
        printf("%.2f %.2f",Max,Min);
}
