#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define Error 1000000
struct LNode
{
    int data;
    struct LNode *next;
};
struct LNode *InitList_L()
{
    struct  LNode *pHead;
    pHead=(struct LNode *)malloc(sizeof(struct LNode));
    pHead->next=NULL;
    return pHead;
}
int GetElem_L(struct LNode *list,int index)
{
    int cnt=1;
    list=list->next;//头结点不存放任何东西
    while(list!=NULL)
    {
        if(cnt==index)
            return list->data;
        list=list->next;
        cnt++;
    }
    return Error;
}
int LocateElem_L(struct LNode *list,int e)
{
    int cnt=1;
    list=list->next;
    while(list!=NULL)
    {
        if(list->data==e)
            return cnt;
        list=list->next;
        cnt++;
    }
    return Error;
}
void ListInsert_L(struct LNode *list,int index,int e)
{
    int cnt=1;
    struct LNode* pNew;
    pNew=(struct LNode *)malloc(sizeof(struct LNode));
    while(list->next!=NULL)
    {
        if(cnt==index)
        {
            pNew->data=e;
            pNew->next=list->next;
            list->next=pNew;
            return ;
        }
        cnt++;
        list=list->next;
    }
    pNew->data=e;
    pNew->next=list->next;
    list->next=pNew;
}
int ListDelete_L(struct LNode *list,int index)
{
    int cnt=1,val;
    while(list->next!=NULL)
    {
        if(cnt==index)
        {
            val=list->next->data;
            list->next=list->next->next;
            return val;
        }
        cnt++;
        list=list->next;
    }
    return Error;
}
void ListDisplay_L(struct LNode *list)
{
    list=list->next;
    while(list!=NULL)
    {
        printf("%d ",list->data);
        list=list->next;
    }
    printf("\n");
}
int main()
{
    struct LNode *pHead;
    pHead=InitList_L();
    ListInsert_L(pHead,1,5);
    ListInsert_L(pHead,1,8);
    ListInsert_L(pHead,2,11);
    ListDisplay_L(pHead);
    ListDelete_L(pHead,2);
    ListInsert_L(pHead,2,66);
    ListDisplay_L(pHead);
    return 0;
}
