#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct List
{
    int len;
    char *elem;
};
void InitList(struct List *list)
{
    list->len=0;
    list->elem=(char*)malloc(sizeof(char)*100);
}
void Insert(struct List *list,char e)
{
    list->elem[list->len++]=e;
}
void Del(struct List *list,char e)
{
    int i,j;
    for(i=0;i<list->len;i++)
    {
        if(e==list->elem[i])
       {

        for(j=i;j<list->len-1;j++)
            list->elem[j]=list->elem[j+1];
            list->len--;
       }
    }
}
void Display(struct List *list)
{
    int i;
    for(i=0;i<list->len-1;i++)
        printf("%c ",list->elem[i]);
        printf("%c\n",list->elem[i]);
}
int main()
{
    int i,j,n,m,e,f;
    char a[100],b[100],s;
    struct List list;
    InitList(&list);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
            scanf("%s",b);
        Insert(&list,b[0]);
        }
        scanf("%s",a);
        Del(&list,a[0]);
        Display(&list);
        InitList(&list);
    }
    return 0;
}
