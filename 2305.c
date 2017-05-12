#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int data;
    struct Stack *next;
};
struct Stack *InitStack()
{
    struct Stack *pHead;
    pHead=(struct Stack*)malloc(sizeof(struct Stack));
    pHead->next=NULL;
}
void Push(struct Stack *stack,int n,int e)
{
    struct Stack *pTai=stack;
    while(stack->next!=NULL)
    {
        n--;
        if(n==0)
        return;
        stack=stack->next;
    }
    struct Stack *pHead;
    pHead=(struct Stack *)malloc(sizeof(struct Stack));
    pHead->data=e;
    pHead->next=pTai->next;
    pTai->next=pHead;
}
int Pop(struct Stack *stack)
{
    int n;
    if(stack->next==NULL)
    return 0;
    n=stack->next->data;
    stack->next=stack->next->next;
    return n;
}
void ListDisplay_L(struct Stack *list)
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
    int m,n,sum,i,e;
    char a[100];
    struct Stack *stack;
    stack=InitStack();
    scanf("%d",&m);
    scanf("%d%d",&n,&sum);
    for(i=0;i<m;i++)
    {
        scanf("%s",a);
        if(a[0]=='a')
        {
            scanf("%d",&e);
            Push(stack,n,e);
        }
    else if(a[0]=='c')
       {
           sum=sum-Pop(stack);
        if(sum<=0)
        printf("chungeV5\n");
        else
        printf("%d\n",sum);
       }
    }
   return 0;
}
