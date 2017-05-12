#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct Point
{
    int x,y;
}data[10000];

int cmp(struct Point a,struct Point b)
{
    return a.x<b.x;
}

int main()
{
    int n,d;
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&data[i].x,&data[i].y);
            if(data[i].y>d)
            printf("-1\n");
        }
        sort(data,data+n,cmp);
        int count=0;
        int min=data[0];
        int i=0;
        while(i<n)
        {
            i++;
            while(data[i].x<=min+d)
            {
                i++;
            }
            min=data[i-1];
            while(data[i].x>)

        }

    }


    return 0;
}
