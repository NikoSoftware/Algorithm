#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int data[10000];

int cmp(double a,double b)
{
    return a>b;
}

int main()
{
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        for(int i=0; i<k; i++)
        {
            scanf("%d",&data[i]);
        }
        sort(data,data+k,cmp);
        double sum=data[0]*1.0;
        for(int i=1; i<k; i++)
        {
            sum=2*sqrt(sum*data[i]);

        }printf("%.3llf\n",sum);


    }

    return 0;
}
