#include<stdio.h>
int main()
{
    int str1[30],str2[30],n,m,diff1,diff2,j,max1,min1,tem,i,max2,min2;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    scanf("%d",&str1[i]);
    for(i=0;i<m;i++);
    scanf("%d",&str2[i]);
    max1=str1[0];
    min2=str1[0];
    min1=str2[0];
    max2=str2[0];
    for(j=1;j<n;j++)
    {
        if(max1<str1[j])
        max1=str1[j];
    }
    for(j=1;j<m;j++)
    {
        if(min1>str2[j])
        min1=str2[j];
    }
    diff1=max1-min1;
    if(diff1>=0)
    {
        printf("%d",diff1);
    }
    else
    {
     for(j=1;j<n;j++)
    {
        if(min2>str1[j])
        min2=str1[j];
    }
    for(j=1;j<m;j++)
    {
        if(max2<str2[j])
        max2=str2[j];
    }
    diff2=max2-min2;
    printf("%d",diff2);
    }
    return 0;
}

