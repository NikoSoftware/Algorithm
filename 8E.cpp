#include<stdio.h>
#include<math.h>
int main()
{
    double m,a[1000],x,y,r;
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<8;j++)
        {
            scanf("%lf",&a[j]);
        }
        printf("%lf ",a[0]+a[2]+a[4]);
        x=(a[0]+a[2]+a[4])/3;
        //printf("%llf ",x);
        y=(a[1]+a[3]+a[5])/3;
        r=sqrt(pow(x-a[0],2.0)+pow(y-a[1],2.0));
        if(r>sqrt(pow(x-a[6],2)+pow(y-a[7],2)))
        printf("Case #%d: Danger\n",i+1);
        else
        printf("Case #%d: Safe\n",i+1);
    }
    return 0;
}
