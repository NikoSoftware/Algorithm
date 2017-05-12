#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c;
    double S,area;
    scanf("%f%f%f",&a,&b,&c);
    S=(a+b+c)/2;
    printf("%.3lf",sqrt(S*(S-a)*(S-b)*(S-c)));
}
