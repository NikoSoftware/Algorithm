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
}
void Insert(struct Node *list,int e)
{
    struct Node *pNew;
    pNew=(struct Node*)malloc(sizeof(struct Node));
    pNew->data=e;
    pNew->next=list->next;
    list->next=pNew;
}
void Display(struct Node *list)
{
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
    int n,i,e;
    struct Node *list;
    list=InitList();
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&e);
            Insert(list,e);
        }
        Display(list);
        list=InitList();
    }
    return 0;
}
