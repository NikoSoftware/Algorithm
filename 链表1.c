#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define Error -10000000
struct List
{
    int *elem;
    int len;
};
void InitList(struct List *list)
{
    list->len=0;
    list->elem=(int *)malloc(sizeof(int)*1000);
    //结构体变量若非指针变量那么用点号取值，
    //否者用->去取出里面的值。
}
void ClearList(struct List *list)
{
    list->len=0;
}
void DestoryList(struct List *list)
{
    list->len=0;
    free(list->elem);
}
bool ListEmpty(struct List *list)
{
    if(list->len==0)
    return true;
    return false;
}
int ListLength(struct List *list)
{
    return list->len;
}
int GetElem(struct List *list,int i)
{
    if(i<1||i>list->len)
    return Error;
    return list->elem[i-1];
}
int LocateElem(struct List *list,int e)
{
    int i;
    for(i=0;i<list->len;i++)
        if(list->elem[i]==e)
        return i+1;
        return i;
}
int PriorElem(struct List *list,int e)
{
    int i;
    for(i=0;i<list->len;i++)
    if(list->elem[i]==e)
    {
        if(i>0)
        return list->elem[i-1];
        //else
        //return Error;
    }
    return Error;
}
int NextElem(struct List *list,int e)
{
    int i;
    for(i=0;i<list->len;i++)
    if(list->elem[i]==e)
    {
        if(i<list->len-1)
        return list->elem[i+1];
    }
    return Error;
}
void ListInsert(struct List *list,int index,int e)//intdex 为第几个；
{
    int i;
    if(index>list->len)
    {
        list->elem[list->len++]=e;
        return;
    }
    for(i=list->len;i>=index;i--)
    list->elem[i]=list->elem[i-1];
    list->elem[index-1]=e;
    list->len++;
}
int ListDelete(struct List *list,int index)
{
    int i,item;
    if(index>list->len)
    return Error;
    item=list->elem[index-1];
    for(i=index-1;i<list->len-1;i++)
    list->elem[i]=list->elem[i+1];
    list->len--;
    return item;
}
void ListDisplay(struct List *list)
{
    int i;
    for(i=0;i<list->len-1;i++)
    printf("%d ",list->elem[i]);
    printf("%d",list->elem[i]);
    printf("\n");
}
int main()
{
    int i,n,s1,s2,s3;
    char a[400];
    struct List ins;
    InitList(&ins);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",a);
        if(strcmp(a,"ins")==0)
        {
            scanf("%d%d",&s1,&s2);
            ListInsert(&ins,s1,s2);
        }
        else if(strcmp(a,"show")==0)
        {
           ListDisplay(&ins);
        }
        else if(strcmp(a,"del")==0)
        {
            scanf("%d",&s3);
            ListDelete(&ins,s3);
        }
    }
    return 0;
}
