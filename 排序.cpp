#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
using namespace std;
int main()
{
    int a[100],i;
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+10);
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
