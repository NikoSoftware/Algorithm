#include<stdio.h>
#include<stdlib.h>
int a=0,b=0;
struct Stack
{
    int data1,data2;
    struct Stack *next;
};
struct Stack *InitStack()
{
    struct Stack *pHead;
    pHead=(struct Stack*)malloc(sizeof(struct Stack));
    pHead->next=NULL;
}
void Pop(struct Stack *stack)
{
    stack->next=stack->next->next;
}
void Push(struct Stack *stack,int n,int data1,int data2)
{
    struct Stack *pTai=stack;
    int i=0;
    while(stack->next!=NULL)
    {
        ++i;
        stack=stack->next;
    }
    struct Stack *pNew=(struct Stack *)malloc(sizeof(struct Stack));
    pNew->data1=data1;
    pNew->data2=data2;
    pNew->next=stack->next;
    stack->next=pNew;
    if(i==n)
    {
        a=pTai->next->data1;
        b=pTai->next->data2;
        Pop(pTai);
    }

}
void Display(struct Stack *stack)
{
    stack=stack->next;
    while(stack!=NULL)
    {
        printf("%d~%d ",stack->data1,stack->data2);
        stack=stack->next;
    }
    printf("\n");
}
int main()
{
    int m,n,data1,data2,i,sum=0;
    struct Stack *stack;
    stack=InitStack();
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
    {

        scanf("%d%d",&data1,&data2);
        Push(stack,n,data1,data2);
        if(i>n)
        {
            sum=sum+b-a*2;
            printf("%d\n",sum);
        }
        else if(i==n)
        printf("hehe\n");
        else
        printf("hungry\n");
       // Display(stack);

    }

    return 0;
}
