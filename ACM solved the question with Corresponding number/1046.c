#include<stdio.h>
#include<math.h>
int main()
{
    int i,n;
    for(i=1000;i<10000;i++)
    {

        if(pow((i/100)+(i%100),2.0)==i)
        printf("%d ",i);
    }
}
