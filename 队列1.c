#include<stdio.h>
#include<stdlib.h>
#define datatype int
struct Queue
{
    datatype *elem;
    int front,rear;
};
void InitQueue(struct Queue *queue)
{
    queue->elem=(datatype*)malloc(sizeof(datatype)*100);
    queue->front=queue->rear=0;
}
void EnQueue(struct Queue *queue,datatype data)
{
    queue->elem[queue->rear]=data;
    queue->rear++;
}
datatype GetHead(struct Queue *queue)
{
    if(queue->rear==0)
    return -1;
    return queue->elem;
}


int main()
{
    return 0;
}
