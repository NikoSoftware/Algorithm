#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int inf=1<<30;
#define maxn 400000
int t[maxn];
void Init()
{
    int i;
    for(i=0;i<maxn;i++)
    t[i]=inf;
}
void Insert(int index,int val)
{
    if(t[index]==inf)
    {
        t[index]=val;
        return;
    }
    if(t[index]>val)
    Insert(index*2,val);
    else
    Insert(index*2+1,val);
}
void PreOrderTraverse(int index)
{
    if(t[index]==inf)
    return;
    printf(" %d",t[index]);
    PreOrderTraverse(index*2);
    PreOrderTraverse(index*2+1);
}
void InOrderTraverse(int index)
{
     if(t[index]==inf)
    return;
    InOrderTraverse(index*2);
    printf(" %d",t[index]);
    InOrderTraverse(index*2+1);
}
void PostOrderTraverse(int index)
{
    if(t[index]==inf)
    return;
    PostOrderTraverse(index*2);
    PostOrderTraverse(index*2+1);
    printf(" %d",t[index]);
}
int main()
{
    int n,i,val;
    while(scanf("%d",&n)!=EOF)
    {
        Init();
        for(i=0;i<n;i++)
        {
            scanf("%d",&val);
            Insert(1,val);
        }
        printf("先序遍历：");
        PreOrderTraverse(1);
        printf("\n");
        printf("中序遍历：");
        InOrderTraverse(1);
        printf("\n");
        printf("后序遍历：");
        PostOrderTraverse(1);
        printf("\n");
    }

    printf("%d\n",inf);
    return 0;
}
