#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define datatype int
struct StackNode
{
    datatype data;
    struct StackNode *next;
};
struct StackNode *InitStack()
{
    struct StackNode *pHead;
    pHead=(struct StackNode*)malloc(sizeof(struct StackNode));
    pHead->next=NULL;
    return pHead;
}
void Push(struct StackNode *stack,datatype data)
{
     struct StackNode *pHead;
    pHead=(struct StackNode*)malloc(sizeof(struct StackNode));
    pHead->data=data;
    pHead->next=stack->next;
    stack->next=pHead;
}
datatype GetTop(struct StackNode *stack)
{
    if(stack->next=NULL)
    return -1;
    return stack->next->data;
}
void Pop(struct StackNode *stack)
{
    if(stack->next==NULL)
    {
        return;
    }
    stack->next=stack->next->next;
}
int StackLenth(struct StackNode *stack)
{
    int cnt=0;
    struct StackNode *p;
    p=stack;
    while(p->next!=NULL)
    {
        p=p->next;
        cnt++;
    }
    return cnt;
}
int main()
{
    struct StackNode *stack;
    stack=InitStack();
    return 0;
}
