#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void  ListInsert_L(struct node *pHead,int e)
{
    struct node *pTai=pHead;
    struct node *pNew;
    pNew=(struct node *)malloc(sizeof(struct node));
    while(pHead->next!=NULL)
    {
        pHead=pHead->next;
    }
    pNew->data=e;
    pNew->next=NULL;
    pHead->next=pNew;
    pHead=pTai;

}
void Display(struct node *pHead)
{
    while(!pHead->next)
    {
        printf("%d ",pHead->data);
    }
    printf("%d",pHead->data);
}
int main()
{
    int i,n,m,s;
    struct node *pHead;
    pHead=(struct node *)malloc(sizeof(struct node));
    pHead->next=NULL;
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=0;i<m+n;i++)
    {
        scanf("%d",&s);
        ListInsert_L(pHead,s);
    }
    Display(pHead);
    return 0;
}
