#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct List
{
    int *elem;
    int len;
};
void InitList(struct List *ins)
{
    ins->len=0;
    ins->elem=(int *)malloc(sizeof(int)*100);
}
void ListInsert(struct List *ins,int index,int val)
{
    int i;
   if(index>ins->len)
    {
        ins->elem[ins->len++]=val;
        return;
    }
    for(i=ins->len;i>=index;i--)
        ins->elem[i]=ins->elem[i-1];
        ins->elem[index-1]=val;
        ins->len=i++;
}
void ListDisplay(struct List *ins)
{
    int i;
    for(i=0;i<ins->len;i++)
    printf("%d ",ins->elem[i]);
    printf("\n");
}
int ListDelete(struct List *ins,int index)
{
    int i,item;
    if(index>ins->len)
    return 1000000;
    item=ins->elem[index-1];
    for(i=index-1;i<ins->len-1;i++)
    ins->elem[i]=ins->elem[i+1];
    ins->len--;
    return item;
}
int main()
{
    int i,n,s1,s2,s3;
    char a[100];
    struct List ins;
    InitList(&ins);
    ListInsert(&ins,1,1);
    ListInsert(&ins,2,2);
    ListInsert(&ins,3,3);
    ListDisplay(&ins);
    /*scanf("%d",&n);
    for(i=0;i<n+1;i++)
    {
        scanf("%s",a);
        getchar;
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
    }*/
    return 0;
}
