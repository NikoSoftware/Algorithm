#include<cl.h>
typedef int ElemType;
#include<c2-1.h>
#include<bo2-1.cpp>
status equal(ElemType c1,ElemType c2)
{
    if(cl==c2)
    return TRUE;
    else
    return FALSE;
}
void Union(SqList &La,SqList Lb)
{
    ElemType e;
    int la_len,Lb_len;
    int i;
    La_len=Listlength(La);
    Lb_len=listlength(Lb);
    for(i=1;i<=Lb_len;i++)
    {
        GetElem(Lb,i,e);
        if(!LocateElem(La,e,equal))
        ListInsert(La,++La_len,e);
    }
}
void print(ElemType &c)
{
    printf("%d",c);
}
void main()
{
    SqList La,Lb;
    Status i;
    int j;
    i=InitList(La);
    if(i==1)
    for(j=1;j<=5;j++)
    i=ListInsert(La,j,j);
    printf("Lb=");
    ListTraverse(Lb,print);
    Union(La,Lb);
    printf("new La= ");
    ListTraverse(La,print);
}
