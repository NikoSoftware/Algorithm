#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *InitList()
{
    struct Node *pHead;
    pHead=(struct Node *)malloc(sizeof(struct Node));
    pHead->next=NULL;
    return pHead;
}
void Insert(struct Node *list,int index,int e)
{
    int i=0;
    struct Node *pHead;
    pHead=(struct Node*)malloc(sizeof(struct Node));
    pHead->data=e;
    while(list!=NULL)
    {
        ++i;
        if(i==index)
        {
            pHead->next=list->next;
            list->next=pHead;
        }
        list=list->next;
    }
}
void Del(struct Node*list,int e)
{
    while(list->next!=NULL)
    {
        if(list->next->data==e)
        {
           list->next=list->next->next;
        }
        list=list->next;
    }
}
void Display(struct Node *list)
{
    if(list->next==NULL)
    return;
    list=list->next;
     printf("%d",list->data);
     list=list->next;
    while(list!=NULL)
    {
        printf(" %d",list->data);
        list=list->next;
    }
    printf("\n");
}
int main()
{
    int n,i,m,e;
    struct Node *list;
    list=InitList();
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        Insert(list,i+1,m);
    }
    scanf("%d",&e);
    Del(list,e);
    Display(list);
    return 0;
}
