#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next1,*next2;
};
struct Node *Initlist()
{
    struct Node *pHead;
    pHead=(struct Node *)malloc(sizeof(struct Node));
    pHead->next1=pHead->next2=NULL;
    return pHead;
}
void Insert(struct Node *pHead,int e)
{
    struct Node *pNew;
    pNew=(struct Node *)malloc(sizeof(struct Node));
    pNew->next1=pNew->next2=NULL;
    pNew->data=e;
    while(pHead->next1!=NULL)
    {
        pHead=pHead->next1;
    }
    pHead->next1=pNew;
    pNew->next2=pHead;
}
void Dell(struct Node *pHead,int index)
{
    while(index--)
    {
        pHead=pHead->next1;
    }
    pHead->next1=pHead->next1->next1;
     pHead->next1->next2=pHead;
}
void Display(struct Node *pHead)
{
    pHead=pHead->next1;
    while(pHead!=NULL)
    {
        printf("%d ",pHead->data);
        pHead=pHead->next1;
    }
    printf("\n");
}
int main()
{
    int i=5,n;
    struct Node *pHead;
    pHead=Initlist();
    printf("插入1,2,3,4,5,");
      Insert(pHead,1);
      Insert(pHead,2);
      Insert(pHead,3);
      Insert(pHead,4);
      Insert(pHead,5);
    printf("\n输入要删除的位置:\n");
    scanf("%d",&n);
    Dell(pHead,n-1);
    Display(pHead);

    return 0;
}
