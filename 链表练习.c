#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
    int data;
    struct Node * pNext;
}NODE, *PNODE;
PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE,int,int);
bool delete_list(PNODE,int,int*);
void sort_list(PNODE);
int main()
{
    int len;
    PNODE pHead=NULL;
    pHead=create_list();
    traverse_list(pHead);
    if(is_empty(pHead))
    printf("链表为空\n");
    else
    printf("链表非空\n");
    len=length_list(pHead);
    printf("长度%d\n",len);
    insert_list(pHead,3,33);
    traverse_list(pHead);


    return 0;
}
PNODE create_list(void)
{
    int len;
    int i;
    int val;
    PNODE pHead=(PNODE)malloc(sizeof(NODE));
    PNODE pTai=pHead;
    pTai->pNext=NULL;
    if(NULL==pHead)
    {
        printf("内存分配失败\n");
        exit(-1);
    }
    printf("请输入你需要生成的链表节点的个数：");
    scanf("%d",&len);
    for(i=0;i<len;i++)
    {
        printf("请输入第%d个节点的值：",i+1);
        scanf("%d",&val);
        PNODE pNew=(PNODE)malloc(sizeof(NODE));
        if(NULL==pNew)
        {
            printf("内存分配失败");
            exit(-1);
        }
        pNew->data=val;
        pTai->pNext=pNew;
        pNew->pNext=NULL;
        pTai=pNew;
    }
    return pHead;
}
void traverse_list(PNODE pHead)
{
    PNODE p=pHead->pNext;
    while(NULL!= p)
    {
        printf("%d ",p->data);
        p=p->pNext;
    }
    printf("\n");
}

bool is_empty(PNODE pHead)
{
    if(NULL==pHead->pNext)
    return true;
    else
    return false;

}

int length_list(PNODE pHead)
{
    PNODE p=pHead->pNext;
    int len=0;
    while(NULL!=p)
    {
        ++len;
        p=p->pNext;
    }
    return len;
}
//在pos插入一个节点val
bool intsert_list(PNODE pHead,int pos,int val)
{
    int i=0;
    PNODE p=pHead->pNext;
    while(NULL!=p&&i<pos-1)
    {
        p=p->pNext;
        ++i;
    }
    if(i>pos-1||NULL==p)
    {
        return false;
    }
    PNODE pNew=(PNODE)malloc(sizeof(NODE));
        if(NULL==pNew)
        {
            printf("内存分配失败");
            exit(-1);
        }
        pNew->data=val;
        PNODE q=p->pNext;
        p->pNext=pNew;
        pNew->pNext=q;

        return true;
}
