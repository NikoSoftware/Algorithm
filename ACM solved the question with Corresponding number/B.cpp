#include<stdio.h>
int main()
{
    int i,j,n,m;
    float a[100],sum;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
            scanf("%f",&a[j]);
            sum+=a[j];
        }
        if(sum/m==0.5)
        printf("yes\n");
        else
        printf("no\n");

    }
    return 0;
}
