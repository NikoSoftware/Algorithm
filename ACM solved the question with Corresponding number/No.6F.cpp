#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int data[600000],c,count1,n;

struct Node
{
    int x,y;
}b[600000];

int cmp(struct Node h,struct Node g)
{
    return h.x<g.x;
}

void two(int a)
{
    if(a>data[count1])
    {
        data[++count1]=a;
        return ;
    }
    if(a<data[0])
    {
        data[0]=a;
        return ;
    }
    if(a<data[count1])
    {
        int l=0,k=count1;
        while(l<=k)
        {
            int mid = (l+k)/2;
            if(a>=data[mid]&&a<=data[mid+1])
            {
                data[mid+1]=a;
                return ;
            }
            else if(a>data[mid])
            l=mid+1;
            else
            k=mid-1;
        }
    }

}

void cal()
{
    data[0]=b[0].y;
    for(int i=1;i<n;i++)
    {
        two(b[i].y);
    }

}


int main()
{
    int k=0;
    while(scanf("%d",&n)!=EOF)
    {
        k++;
        count1=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&b[i].x,&b[i].y);
        }
        sort(b,b+n,cmp);
        cal();
        if(count1==0)
        printf("Case %d:\nMy king, at most %d road can be built.\n\n",k,count1+1);
        else
        printf("Case %d:\nMy king, at most %d roads can be built.\n\n",k,count1+1);

    }
    return 0;
}
