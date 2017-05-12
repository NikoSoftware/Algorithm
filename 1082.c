#include<stdio.h>
#include<math.h>
int main()
{
    float a[20],i,j,sum;
    while(scanf("%f%f%f%f",&a[0],&a[1],&a[2],&a[3])!=EOF)
    {
        sum=(a[2]-a[0])*(a[2]-a[0])+(a[3]-a[1])*(a[3]-a[1]);
         printf("%.2f\n",sqrt(sum));
    }
    return 0;
}
