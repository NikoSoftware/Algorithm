#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    int *elem;
    int size;
    int front,rear;
};
void Init(struct Node *list)
{
    list->elem=(int *)malloc(sizeof(int)*10);
    list->size=9;
    list->front=list->rear=0;
}
int  push(struct Node *list)
{
    if(list->front%list->size==(list->rear+1)%list->size)
    {
        printf("ÄÚ´æÒÑÂú!\n");
        return 1;
    }
    else
    {
        printf("²åÈë£º");
        scanf("%d",&list->elem[list->rear++]);
        return 0;
    }
}
void Pop(struct Node*list)
{
    list->front++;
}
int main()
{
    struct Node list;
    Init(&list);
    while(1)
    {
        if(push(&list))
        {
            break;
        }
    }
    Pop(&list);
    while(1)
    {
        if(push(&list))
        {
            break;
        }
    }
}
