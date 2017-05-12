#include<stdio.h>
#include<algorithm>
using namespace std;

struct node
{
    long long x,y;
} data[200000];

double cmp(struct node a,struct node b)
{
    return a.x*b.y<=b.x*a.y;
}

int main()
{
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        for(int i=0;i<k;i++)
        {
            scanf("%lld%lld",&data[i].x,&data[i].y);
        }
        sort(data,data+k,cmp);
        long long sum=0,count=0;
        for(int i=0;i<k;i++)
        count+=data[i].y;
        for(int i=0;i<k;i++)
        {
            count-=data[i].y;
            sum+=data[i].x*2*count;
        }printf("%lld\n",sum);
    }

    return 0;
}
