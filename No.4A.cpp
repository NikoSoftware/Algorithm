#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct Point
{
    int x,y;
}data[100000];

int cmp(Point a,Point b)
{
    if(a.x==b.x)
    return a.y<b.y;
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
        }
        sort(data,data+n,cmp);
        int max=0;
        int sum=0;
        int top=0;
        while(max<d)
        {
            int min=max+1;
            for(int i=top;i<n;i++)
            {
                if(data[i].x<=min&&data[i].y>=min)
                max=max>data[i].y?max:data[i].y;
                else if(data[i].x>min)
                {
                    top=i;
                    break;
                }
            }
            if(min>max)
            break;
            else
            sum++;
        }
        if(max>=d)
        printf("%d\n",sum);
        else
        printf("-1\n");
    }

    return 0;
}
