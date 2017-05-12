#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE;
PNODE ins(PNODE,int,int);
void traverse_list(PNODE);
int main()
{
    int i,x=0,val;
    PNODE phead=(PNODE)malloc(sizeof(NODE));
    phead->next=NULL;
     if(NULL==phead)
    {
        printf("内存分配失败\n");
        exit(-1);
    }
    for(i=0;i<3;i++)
    {
      scanf("%d",&val);
    ins(phead,x,val);
    }
    traverse_list(phead);
    return 0;
}
PNODE ins(PNODE phead,int x,int val)
{
    PNODE ptai=phead;
    PNODE pnew=(PNODE)malloc(sizeof(NODE));
         if(NULL==pnew)
    {
        printf("内存分配失败\n");
        exit(-1);
    }
    pnew->data=val;
    pnew->next=ptai;
    ptai->next=pnew;

    return phead;
}
void traverse_list(PNODE phead)
{
    PNODE p=phead->next;
    while(NULL!=p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}






