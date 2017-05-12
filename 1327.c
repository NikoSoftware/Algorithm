#include<stdio.h>
int di(int m)
{
    if(m==1)
    return 1;
    return 2*(di(m-1)+1);
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",di(n));


}
