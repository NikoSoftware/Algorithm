#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int top ;
    char *elem;
};
void InitStack(struct Node *stack)
{
    stack->top=0;
    stack->elem=(char *)malloc(sizeof(char)*100);
}
void Insert(struct Node *stack,int indax,char e)
{
    int i;
    if(indax>stack->top)
    {
        stack->elem[stack->top]=e;
        stack->top++;
        return;
    }
    for(i=stack->top;i>=indax;i--)
    stack->elem[i]=stack->elem[i-1];
    stack->elem[indax-1]=e;
    stack->top++;
}
void Display(struct Node *stack)
{
    int i;
    for(i=0;i<stack->top;i++)
    printf("%c",stack->elem[i]);
    printf("\n");
}
int main()
{
    int i,a;char b;
    struct Node stack;
    InitStack(&stack);
    i=0;
    while(scanf("%d ",&a)!=EOF)
    {
        scanf("%c",&b);
        Insert(&stack,a,b);
    }
    Display(&stack);
    return 0;
}
