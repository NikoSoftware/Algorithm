#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int Max=-10000,Min=10000,z=0;
struct Node
{
  int data;
  struct Node *next;
};
struct Node *Init()
{
    struct Node *pHead;
    pHead=(struct Node*)malloc(sizeof(struct Node));
    pHead->next=NULL;
    return pHead;
}
void Insert(struct Node *list,int e)
{
    struct Node*pNew;
    pNew=(struct Node*)malloc(sizeof(struct Node));
    pNew->next=NULL;
    pNew->data=e;
    pNew->next=list->next;
    list->next=pNew;
}
void Compare(struct Node *list)
{
    list=list->next;
    if(list==NULL)
    z=1;
    while(list!=NULL)
    {
        if(Max<list->data)
        Max=list->data;
        if(Min>list->data)
        Min=list->data;
        list=list->next;
    }
}

int main()
{
    int i,n,m;
    struct Node *list;
    list=Init();
    while(scanf("%d",&n)!=EOF)
    {
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        Insert(list,m);
    }
    Compare(list);
    if(z==1)
    printf("Empty list\n");
    else
    printf("%d %d\n",Max,Min);
        Max=-10000,Min=10000,z=0;
    list=Init();
    }
    return 0;
}
