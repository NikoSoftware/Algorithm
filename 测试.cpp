#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int i,a[100];
    for(i=0;i<5;i++)
    scanf("%d",&a[i]);
    sort(a+2,a+5);
    for(i=0;i<5;i++)
    printf("%d ",a[i]);
       return 0;
}
