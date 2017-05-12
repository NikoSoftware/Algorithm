#include<stdio.h>
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
}
void Insert(struct List *list,int e)
{
    list->elem[list->len++]=e;
}
int chu(struct List *list,int index)
{
    return list->elem[index];
}
void Del(struct List *list,int index)
{
    int i;
    for(i=index;i<list->len;i++)
    {
        list->elem[i]=list->elem[i+1];
    }
    list->len--;
}
void Display(struct List *list)
{
    int i;
    for(i=0;i<list->len-1;i++)
    printf("%d ",list->elem[i]);
    printf("%d\n",list->elem[i]);
}
int main()
{
    int i,j,n,m,z=0;
    struct List list;
    InitList(&list);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        Insert(&list,m);
    }
    for(i=0;i<n-1-z;i++)
    {
        for(j=i+1;j<n-z;j++)
        {
            if(chu(&list,i)==chu(&list,j))
            {
                Del(&list,j);
                z++;
            }
        }
    }
    Display(&list);

    return 0;
}
