#include<stdio.h>
#include<stdlib.h>
#define datatype int
#define maxn 4
struct Queue
{
    datatype *elem;
    int front,rear;
};
void InitQueue(struct Queue *queue)
{
    queue->elem=(datatype*)malloc(sizeof(datatype)*maxn);
    queue->front=queue->rear=0;
}
void EnQueue(struct Queue *queue,datatype data)
{
    if(queue->rear-queue->front==3||queue->front-queue->rear==1)
    return;

    queue->elem[queue->rear]=data;
    if(queue->rear==maxn-1)
    {
        queue->rear=0;
    }
    else
    {
        queue->rear++;
    }
}
datatype GetHead(struct Queue *queue)
{

    return queue->elem[queue->front];
}
void DeQueue(struct Queue *queue)
{
    if(queue->front==queue->rear)
    {
        return;
    }
    queue->front++;
    queue->front%maxn;
}

int main()
{
    struct Queue dui;
    InitQueue(&dui);
    EnQueue(&dui,1);
    printf("%d",GetHead(&dui));
    EnQueue(&dui,2);
    printf("%d",GetHead(&dui));
    EnQueue(&dui,3);
    printf("%d",GetHead(&dui));
    DeQueue(&dui);
    EnQueue(&dui,4);
    EnQueue(&dui,5);
    return 0;
}
