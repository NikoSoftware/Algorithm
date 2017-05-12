#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *InitList()
{
    struct Node *pHead;
    pHead=(struct Node*)malloc(sizeof(struct Node));
    pHead->next=NULL;
    return pHead;
}
void Insert(struct Node *list,int index,int e)
{
    int i=0;
    struct Node *pNew;
    pNew=(struct Node*)malloc(sizeof(struct Node));
    pNew->data=e;
    while(list->next!=NULL)
    {
        ++i;
        if(index==i)
        {
            pNew->next=list->next;
            list->next=pNew;
            return;
        }
        list=list->next;
    }
    pNew->next=list->next;
    list->next=pNew;
}
void Del(struct Node *list,int index)
{
    int i=0;
    while(list->next!=NULL)
    {
        ++i;
        if(index==i)
        list->next=list->next->next;
        list=list->next;
    }
}
void Display(struct Node *list)
{
    list=list->next;
    if(list==NULL)
    return;
    printf("%d",list->data);
    list=list->next;
    while(list!=NULL)
    {
        printf(" %d",list->data);
        list=list->next;
    }
    //printf("%d",list->data);
    printf("\n");
}
int main()
{
    struct Node *list;
    list=InitList();
    int i,n,s1,s2,s3;
    char a[400];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",a);
        if(strcmp(a,"ins")==0)
        {
            scanf("%d%d",&s1,&s2);
            Insert(list,s1,s2);
        }
        else if(strcmp(a,"show")==0)
        {
           Display(list);
        }
        else if(strcmp(a,"del")==0)
        {
            scanf("%d",&s3);
            Del(list,s3);
        }
    }
   //Insert(list,1,50);
   // Insert(list,2,56);
    //Insert(list,1,2);
    //Display(list);

    return 0;
}
