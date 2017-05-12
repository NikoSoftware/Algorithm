#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *InitList()
{
    struct Node *pHead=(struct Node*)malloc(sizeof(struct Node));
    pHead->next=NULL;
    return pHead;
}
void Push(struct Node *list,int e)
{
    struct Node *pNew;
    pNew=(struct Node*)malloc(sizeof(struct Node));
    pNew->data=e;
    while(list->next!=NULL)
    {
        list=list->next;
    }
    pNew->next=list->next;
    list->next=pNew;
}
void Display(struct Node *list)
{
    list=list->next;
    while(list!=NULL)
    {
        printf("%d ",list->data);
        list=list->next;
    }
}
void Del(struct Node *list,int min,int max)
{
    struct Node *pHead=list;
    while(list->next!=NULL)
    {
        if(list->next->data>=min||list->next->data<=max)
        list->next=list->next->next;
        list=list->next;
    }

    list=pHead;
    Del(list,min,max);
   // if(list->data>=min||list->data<=max)
    //    list->next=list->next->next;
   /* pHead=pHead->next;
    if(pHead==NULL)
    return;
    printf("%d",pHead->data);
    pHead=pHead->next;
        while(pHead!=NULL)
        {
            printf(" %d",pHead->data);
            pHead=pHead->next;
        }
        printf("\n");*/
}
int main()
{
    int n,i,m,min,max;
    struct Node *list;
    list=InitList();
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            Push(list,m);
        }
        scanf("%d %d",&min,&max);
        Display(list);
        Del(list,min,max);
        list=InitList();
    }
    return 0;
}
