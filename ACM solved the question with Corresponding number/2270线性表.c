#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
    list->elem[index-1]=e;
    list->len++;
}
int ListDelete(struct List *list,int min,int max)
{
    int i,j;
    for(i=0;i<list->len;i++)
    {
        if(list->elem[i]>=min||list->elem[i]<=max)
        for(j=i;j<list->len-1;j++)
            list->elem[j+1]=list->elem[j];
    }
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
    int m,e,min,max,i;
    struct List list;
    InitList(&list);
    while(scanf("%d",&m)!=EOF)
    {
        for(i=0;i<m;i++)
        {
            scanf("%d",&e);
            ListInsert(&list,i,e);
        }
        scanf("%d%d",&min,&max);
        ListDelete(&list,min,max);
        ListDisplay(&list);
        InitList(&list);
    }
    return 0;
}
