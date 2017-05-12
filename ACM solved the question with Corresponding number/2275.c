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
    list->elem[index]=e;
    list->len++;
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
    int i,n,m,e;
    struct List list;
    InitList(&list);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        ListInsert(&list,i,m);
    }
    scanf("%d%d",&i,&e);
    ListInsert(&list,i-1,e);
    ListDisplay(&list);
    return 0;
}





