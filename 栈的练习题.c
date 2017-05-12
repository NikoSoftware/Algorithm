#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *InitStack()
{
    struct Node *pHead;
    pHead=(struct Node *)malloc(sizeof(struct Node));
    pHead->next=NULL;
    return pHead;
}
void Push(struct Node *stack,int e)
{
   struct Node *pHead;
   pHead=(struct Node *)malloc(sizeof(struct Node));
   pHead->data=e;
   pHead->next=stack->next;
   stack->next=pHead;
}
void Pop(struct Node *stack)
{
    if(stack->next=NULL)
    {
        return ;
    }
    stack->next=stack->next->next;
}
void Display(struct Node *stack)
{
    struct Node *pHead=stack;
    stack=stack->next;
    while(stack!=NULL)
    {
        printf("%d",stack->data);
        stack=stack->next;
    }
    printf("\n");
}
int main()
{
    int e;
    long long n;
    struct Node *stack;
    stack=InitStack();
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
        printf("%d",0);
    while(n>0)
    {
        e=n%2;
        n=n/2;
        Push(stack,e);
    }
    Display(stack);
    stack=InitStack();
    }

    return 0;
}
