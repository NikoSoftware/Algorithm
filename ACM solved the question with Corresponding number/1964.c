#include<stdio.h>
#include<string.h>
int main()
{
    int a,n=0,m=0,i=0;
    while(scanf("%d",&a)!=EOF)
    {
        if(a<=0)
        break;
        else if(a>=85)
        n++;
        else if(a>=60)
        m++;
        else
        i++;
    }
    printf(">=85:%d\n60-84:%d\n<60:%d\n",n,m,i);
}
