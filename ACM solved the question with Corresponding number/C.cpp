#include<stdio.h>
int main()
{
    int i,j;
    float n,m;
    scanf("%d",&j);
    for(i=0;i<j;i++)
    {
        scanf("%f%f",&n,&m);
        printf("%f\n",n*m);
    }
    return 0;
}
