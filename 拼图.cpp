#include <iostream>
using namespace std;

int queue[1000000], front, rear;
int BFS(int a, int b)
{
　　int result=0;

　　front=0;
　　rear=2;

　　queue[0]=a;
　　queue[1]=b;

　　while (front<rear)
　　{
　　　　int x=queue[front++];

　　　　if (x==1)
　　　　{
　　　　　　result++;
　　　　　　continue;
　　　　}

　　　　queue[rear++]=1;
　　　　queue[rear++]=--x;
　　}

　　return result;
}

int main()
{
　　int a,b;
　　cin>>a>>b;
　　cout<<BFS(a,b);
　　return 0;
}

