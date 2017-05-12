#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int data;
    struct Stack *next;
};
struct Stack* Init()
{
    struct Stack *pHead;
    pHead=(struct Stack *)malloc(sizeof(struct Stack));
    pHead->next=NULL;
    return pHead;
}
void Insert(struct Stack *stack,int e)
{
    while(stack->next!=NULL)
    {
        stack=stack->next;
    }
    struct Stack *pHead;
    pHead=(struct Stack *)malloc(sizeof(struct Stack));
    pHead->data=e;
    pHead->next=stack->next;
    stack->next=pHead;
}
void Display(struct Stack *stack)
{
    stack=stack->next;
    if(stack!=NULL)
    {
        printf("%d",stack->data);
        stack=stack->next;
    }
    while(stack!=NULL)
    {
        printf(" %d",stack->data);
        stack=stack->next;
    }
    printf("\n");
}

int main()
{
    int n,m,i;
    struct Stack *stack;
    stack=Init();
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        Insert(stack,m);
    }
    Display(stack);
    return 0;
}


