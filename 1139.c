#include<stdio.h>
#include<string.h>
struct date
{
    int day;
    char c;
    int month;
    char d;
    int year;
}a[6],tem;
int main()
{
    int i,j;
    for(i=0; i<6; i++)
    {
        scanf("%d%c%d%c%da",&a[i].day,&a[i].c,&a[i].month,&a[i].d,&a[i].year);
    }
    for(i=0; i<5; i++)
    {
        for(j=i+1; j<5; j++)
        {
            if(a[i].year>a[j].year)
            {
                tem=a[i];
                a[i]=a[j];
                a[j]=tem;
            }
            if(a[i].year==a[j].year)
            {
                if(a[i].month>a[j].month)
                {
                    tem=a[i];
                    a[i]=a[j];
                    a[j]=tem;
                }
                if(a[i].month==a[j].month)
                {
                    if(a[i].day>a[j].day)
                    {
                    tem=a[i];
                    a[i]=a[j];
                    a[j]=tem;
                    }
                }
            }
        }
    }
    for(i=0; i<6; i++)
    {
        printf("%02d%c%02d%c%02d\n",a[i].day,a[i].c,a[i].month,a[i].d,a[i].year);
    }
    return 0;
}
