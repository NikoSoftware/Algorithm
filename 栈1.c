#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define Error -10000000
struct Stack
{
    int *elem;
    int top;
};
void InitStack(struct Stack *stack)
{
    stack->top=0;
    stack->elem=(char *)malloc(sizeof(char)*1000);
    //结构体变量若非指针变量那么用点号取值，
    //否者用->去取出里面的值。
}
void Push(struct Stack *stack,int data)
{
    stack->elem[stack->top]=data;
    stack->top++;
}
int GetTop(struct Stack *stack)
{
    stack->top--;
    return stack->elem[stack->top];
}
/*int GetTop2(struct Stack stack)
{
    stack.top--;
    return stack.elem[stack.top];
}
*/
void Pop(struct Stack *stack)
{
    stack->top--;
}
int main()
{
    int s[100];
    int i;
    struct Stack stack;
    InitStack(&stack);
    scanf("%s",s);
    push(&stack,s[0]);
    for(i=1;i<strlen(s);i++)
    {
        if(s[i]==')')
        {
            if(GetTop(&stack)=='(')
               {
                   Pop(&stack);
               }
               else
               {
                   push(&stack,s[i]);
               }
        }
        else
        {
            Push(&stack,s[i]);
        }
    }
    return 0;
}
