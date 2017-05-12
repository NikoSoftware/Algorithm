#include<stdio.h>
int product(int m)
{
    int sum=1,i;

    for(i=1;i<=m;i++)
    {
        sum*=i;
    }
    return sum;
}
int main()
{
    int m,n;
    float sum;
    scanf("%d%d",&m,&n);
    sum=product(m)*1.0/product(n)/product(m-n);
    printf("%.0lf\n",sum);

}
