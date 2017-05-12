#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=10100;

int n,m,t[maxn];

void UpdateUp(int indax)
{
    if(indax==1)
    return;
    if(t[indax]>t[index>>1])
    {
        swap(t[indax],t[index>>1]);
        UpdateUp(indax>>1)
    }
}
void UpdateDown(int index)
{
    if(indax>=m)
    return;
    if((indax<<1)<m&&t[index]>t[index<<1])
    {
        swap(t[index],t[index<<1]);
        UpdateDown(index<<1);

    }
    if((indax<<1)<m&&t[indax]>t[index*2+1])
    {
        swap(t[index],t[index*2+1]);
        UpdateDown(index*2+1);
    }
}




int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        m=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",t[++m]);
            UpdateUp(m);

        }
        for(int i=0;i<n;i++)
        {
            printf("%d",t[1]);
            swapx(t[i],t[m--]);n
        }


    }

}
