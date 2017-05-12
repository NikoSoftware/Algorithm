#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *prior,*next;
};
struct Node *Init()
{
    struct Node *pHead;
    pHead=(struct Node *)malloc(sizeof(struct Node));
    pHead->prior=pHead->next=NULL;
}
void Insert(struct Node*list,int e)
{
    struct Node *pHead;
    pHead=(struct Node*)malloc(sizeof(struct Node));
    while(list->next!=NULL)
    {
        list=list->next;
    }
    pHead->data=e;
    pHead->next=NULL;
    list->next=pHead;
    pHead->prior=list;
}
void Display(struct Node *list)
{
    if(list->next==NULL)
    return;
    list=list->next;
    printf("%d",list->data);
    while(list->next!=NULL)
    {
        list=list->next;
        printf(" %d",list->data);
    }
    printf("\n");
    printf("%d",list->data);
    list=list->prior;
    while(list->prior!=NULL)
    {
        printf(" %d",list->data);
        list=list->prior;
    }
}

int main()
{
    int n,i,m;
    struct Node *list;
    list=Init();
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            Insert(list,m);
        }
        Display(list);
    }
    return 0;
}
