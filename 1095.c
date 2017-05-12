#include<stdio.h>
int main()
{
    int i;
    float sum,max,min,c;
    float ave,a[100];
    char b[100];
    while(scanf("%f",&c)!=EOF)
    {
        for(i=0; i<6; i++)
        {
            scanf("%f",&a[i]);
        }
        getchar();
        gets(b);
        max=min=c;
        sum=c;
        for(i=0; i<6; i++)
        {
            if(max<a[i])
                max=a[i];
            if(min>a[i])
                min=a[i];
            sum+=a[i];
        }
        sum=sum-max-min;
        ave=sum/5;
        printf("%s %0.2f\n",b,ave);
    }
}
