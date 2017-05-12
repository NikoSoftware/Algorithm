#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int n=0;
struct Node
{
    char Name[100];
    char Sex[100];
    char Num[100];
    char Math[100],Chinese[100],English[100];
    struct Node *next;
};
struct Node* Initlist()
{
    struct Node *pHead;
    pHead=(struct Node*)malloc(sizeof(struct Node));
    pHead->next=NULL;
    return pHead;
}
void Magezine(struct Node *list)
{
    printf("姓名：%s\t性别：%s\t学号: %s\t数学：%s\t语文：%s\t英语：%s\n",
           list->Name,list->Sex,list->Num,list->Math,list->Chinese,list->English);
}
int chengji(char *p)
{
    int m=0,f,flag=0,i,d;
    float sum=0;
    m=strlen(p);
    for(i=0,d=0; i<m; i++)
    {
        if(p[i]!='.')
            d++;
        else
            break;
    }
    if(m==d+1)
    flag=1;
    else if(p[0]=='.')
    flag=1;
    else if(p[0]=='0')
    {
        if(p[1]!='.'&&m>1)
            flag=1;
    }
    for(i=d+1; i<m; i++)
        if(p[i]=='.')
        {
            flag=1;
            break;
        }
    for(i=0; i<m; i++)
    {
        if(flag==1)
            break;
        if(p[i]<'0'||p[i]>'9')
        {
            if(p[i]!='.')
            {
                flag=1;
                break;
            }
        }
        if(p[i]=='.')
            continue;
        sum+=(p[i]-'0')*pow(10,--d);
    }
    if(flag==0&&sum>=0&&sum<=150)
        return 1;
    return 0;
}
void Insert(struct Node *pHead)
{
    char a[10],nan[20]= {"男"},nv[20]= {"女"};
    while(1)
    {

        struct Node *pNew;
        pNew=(struct Node*)malloc(sizeof(struct Node));
        pNew->next=NULL;
        printf("输入名字：");
        scanf("%s",pNew->Name);
        while(1)
        {
            printf("输入性别 男/女：");
            scanf("%s",pNew->Sex);
            if(strcmp(pNew->Sex,nan)==0||strcmp(pNew->Sex,nv)==0)
                break;
            printf("输入错误!\n");
        }
        printf("输入学号:");
        scanf("%s",pNew->Num);
        while(1)
        {
            printf("数学：");
            scanf("%s",pNew->Math);
            if(chengji(pNew->Math))
                break;
            printf("输入错误，重新输入!\n");
        }
        while(1)
        {
            printf("语文：");
            scanf("%s",pNew->Chinese);
            if(chengji(pNew->Chinese))
                break;
            printf("输入错误，重新输入!\n");
        }
        while(1)
        {
            printf("英语：");
            scanf("%s",pNew->English);
            if(chengji(pNew->English))
                break;
            printf("输入错误，重新输入!\n");
        }
        pNew->next=pHead->next;
        pHead->next=pNew;
        n++;
        printf("是否继续插入，是请输入 1\n");
        scanf("%s",a);
        system("cls");
        if(a[0]!='1')
        {
            return ;
        }
    }
}
void Display(struct Node *list)
{
    if(n==0)
    {
        printf("内部无值！\n");
        return ;
    }
    list=list->next;
    while(list!=NULL)
    {
        Magezine(list);
        list=list->next;
    }
}
struct Node* search(struct Node *list)
{
    char a[100],b[100],c[100];
    Display(list);
    if(n==0)
    return list;
    printf("输入：1.姓名搜索，2.学号搜索\n");
    while(1)
    {
        scanf("%s",b);
        if(b[0]>='1'&&b[0]<='2')
            break;
        printf("输入有误，请重新输入\n");
    }
    if(b[0]=='1')
    {
        printf("请输入用户的名字：");
        scanf("%s",a);
        list=list->next;
        while(list!=NULL)
        {
            if(strcmp(a,list->Name)==0)
            {
                Magezine(list);
                return list;
            }
            list=list->next;
        }
        printf("无此搜索\n");
        return list;
    }
    if(b[0]=='2')
    {
        printf("请输入用户的学号：");
        scanf("%s",a);
        list=list->next;
        while(list!=NULL)
        {
            if(strcmp(a,list->Num)==0)
            {
                Magezine(list);
                return list;
            }
            list=list->next;
        }
        printf("无此搜索\n");
        return list;
    }
}
void change(struct Node *list)
{
    char a[100],b[100],c[100];
    char nan[20]= {"男"},nv[20]= {"女"};
    if((list=search(list))!=NULL)
    {
        printf("1.姓名修改，2.性别修改，3.学号修改，4.数学成绩修改，5.语文修改，6.英语修改\n");
        while(1)
        {
            scanf("%s",c);
            if(c[0]>='0'&&c[0]<='9')
                break;
            printf("输入有误，请重新输入\n");
        }
        if(c[0]=='1')
        {
            printf("姓名：");
            scanf("%s",list->Name);
        }
        else if(c[0]=='2')
        {
            while(1)
            {
                printf("输入性别 男/女：");
                scanf("%s",list->Sex);
                if(strcmp(list->Sex,nan)==0||strcmp(list->Sex,nv)==0)
                    break;
                printf("输入错误!\n");
            }
        }
        else if(c[0]=='3')
        {
            printf("学号：");
            scanf("%s",list->Num);

        }
        else if(c[0]=='4')
        {
            while(1)
            {
                printf("数学：");
                scanf("%s",list->Math);
                if(chengji(list->Math)==1)
                    break;
                printf("输入错误，请重新输入!\n");
            }
        }
        else if(c[0]=='5')
        {
            while(1)
            {
                printf("语文：");
                scanf("%s",list->Chinese);
                if(chengji(list->Chinese)==1)
                    break;
                printf("输入错误，请重新输入!\n");
            }
        }
        else if(c[0]=='6')
        {
            while(1)
            {
                printf("英语：");
                scanf("%s",list->English);
                if(chengji(list->English)==1)
                    break;
                printf("输入错误，请重新输入!\n");
            }
        }
    }
}
void Del(struct Node *list)
{
    char a[100],b[100],c[100];
    Display(list);
    if(n==0)
    return ;
    printf("输入：1.姓名搜索，2.学号搜索\n");
    while(1)
    {
        scanf("%s",b);
        if(b[0]>='1'&&b[0]<='2')
            break;
        printf("输入有误，请重新输入\n");
    }
    if(b[0]=='1')
    {
        printf("请输入用户的名字：");
        scanf("%s",a);
        while(list->next!=NULL)
        {
            if(strcmp(a,list->next->Name)==0)
            {
                Magezine(list->next);
                list->next=list->next->next;
                printf("删除成功！\n");
                n--;
                return ;
            }
            list=list->next;
        }
        printf("无此搜索\n");
    }
    if(b[0]=='2')
    {
        printf("请输入用户的学号：");
        scanf("%s",a);
        while(list->next!=NULL)
        {
            if(strcmp(a,list->next->Num)==0)
            {
                Magezine(list->next);
                list->next=list->next->next;
                printf("删除成功！\n");
                n--;
                return ;
            }
            list=list->next;
        }
        printf("无此搜索\n");
    }
}
int Com(char *p,char *q)
{
    int z;
    long long n1,n2,sum1=0,sum2=0;
    n1=strlen(p);
    n2=strlen(q);
    for(z=0; z<n1; z++)
    {
        sum1+=(p[z]-'0')*pow(10.0,n1-z-1);
    }
    for(z=0; z<n1; z++)
    {
        sum2+=(q[z]-'0')*pow(10.0,n1-z-1);
    }
    if(sum1>=sum2)
        return 0;
    else
        return 1;
}
void Jaohuan(struct Node *p,struct Node *q)
{
    struct Node *pTai;
    char a[100];
    pTai=(struct Node*)malloc(sizeof(struct Node));
    pTai->next=NULL;

    strcpy(a,p->Name);
    strcpy(p->Name,q->Name);
    strcpy(q->Name,a);

    strcpy(a,p->Sex);
    strcpy(p->Sex,q->Sex);
    strcpy(q->Sex,a);

    strcpy(a,p->Num);
    strcpy(p->Num,q->Num);
    strcpy(q->Num,a);

    strcpy(a,p->Math);
    strcpy(p->Math,q->Math);
    strcpy(q->Math,a);

    strcpy(a,p->Chinese);
    strcpy(p->Chinese,q->Chinese);
    strcpy(q->Chinese,a);

    strcpy(a,p->English);
    strcpy(p->English,q->English);
    strcpy(q->English,a);

}
void Order(struct Node *list)
{
    int i,j;
    char b[100];
    struct Node *tem1,*p,*q,*tem2;
    if(n==0)
    {
        printf("内部无值\n");
        getchar();
        return;
    }
    printf("1.学号排序，2数学成绩排序，3.语文成绩排序，4.英语成绩排序\n");
    while(1)
    {
        scanf("%s",b);
        if(b[0]>='0'&&b[0]<='9')
            break;
        printf("输入有误，请重新输入\n");
    }
    if(b[0]=='1')
    {
        for(i=0,p=list->next; i<n-1; i++,p=p->next)
            for(j=i+1,q=p->next; j<n; j++,q=p->next)
            {
                if(Com(p->Num,q->Num)==0)
                {
                    Jaohuan(p,q);
                }
            }
    }
    if(b[0]=='2')
    {
        for(i=0,p=list->next; i<n-1; i++,p=p->next)
            for(j=i+1,q=p->next; j<n; j++,q=p->next)
            {
                if(Com(p->Math,q->Math))
                {
                    Jaohuan(p,q);
                }
            }
    }
    if(b[0]=='3')
    {
    for(i=0,p=list->next; i<n-1; i++,p=p->next)
        for(j=i+1,q=p->next; j<n; j++,q=p->next)
        {
            if(Com(p->Chinese,q->Chinese))
            {
                Jaohuan(p,q);
            }
        }
    }
    if(b[0]=='4')
    {
        for(i=0,p=list->next; i<n-1; i++,p=p->next)
        for(j=i+1,q=p->next; j<n; j++,q=p->next)
        {
            if(Com(p->English,q->English))
            {
                Jaohuan(p,q);
            }
        }
    }
    Display(list);
}
void magezine()
{
    printf("\n\n\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\t\n");
    printf("\t■                                                      ■\t\n");
    printf("\t■                     1.插入操作                       ■\t\n");
    printf("\t■                                                      ■\t\n");
    printf("\t■                     2.打印操作                       ■\t\n");
    printf("\t■                                                      ■\t\n");
    printf("\t■                     3.更改操作                       ■\t\n");
    printf("\t■                                                      ■\t\n");
    printf("\t■                     4.排序操作                       ■\t\n");
    printf("\t■                                                      ■\t\n");
    printf("\t■                     5.搜索操作                       ■\t\n");
    printf("\t■                                                      ■\t\n");
    printf("\t■                     6.删除操作                       ■\t\n");
    printf("\t■                                                      ■\t\n");
    printf("\t■                     0.退出程序                       ■\t\n");
    printf("\t■                                                      ■\t\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\t\n");
}
int main()
{


    struct Node *list;
    list=Initlist();
    while(1)
    {
        char a[100],b[100];
        magezine();
        while(1)
        {
            scanf("%s",a);
            if(a[0]>='0'&&a[0]<='6')
                break;
            printf("输入错误，请重新输入\n");
        }
        if(a[0]=='1')
        {
            system("cls");
            Insert(list);
        }
        if(a[0]=='2')
        {
            system("cls");
            Display(list);
            while(1)
            {
                printf("\n\n\t\t还回主界面请输入 0\n");
                scanf("%s",b);
                if(b[0]=='0')
                    break;
            }
        }
        if(a[0]=='3')
        {
            system("cls");
            change(list);
            while(1)
            {
                printf("\n\n\t\t还回主界面请输入 0\n");
                scanf("%s",b);
                if(b[0]=='0')
                    break;
            }
        }
        if(a[0]=='4')
        {
            system("cls");
            Order(list);
            while(1)
            {
                printf("\n\n\t\t还回主界面请输入 0\n");
                scanf("%s",b);
                if(b[0]=='0')
                    break;
            }
        }
        if(a[0]=='5')
        {
            system("cls");
            search(list);
            while(1)
            {
                printf("\n\n\t\t还回主界面请输入 0\n");
                scanf("%s",b);
                if(b[0]=='0')
                    break;
            }
        }
        if(a[0]=='6')
        {
            system("cls");
            Del(list);
            while(1)
            {
                printf("\n\n\t\t还回主界面请输入 0\n");
                scanf("%s",b);
                if(b[0]=='0')
                    break;
            }
        }
        if(a[0]=='0')
        {
            break;
        }
        system("cls");
    }

    return 0;
}





/*for(pHead_1=list; pHead_1->next->next!=NULL; pHead_1=pHead_1->next)
           for(pHead_2=pHead_1->next; pHead_2->next!=NULL; pHead_2=pHead_2->next)
           {
               puts("aaa");
               if(Com(pHead_1->next->Num,pHead_2->next->Num)==0)
               {
                   tem1=pHead_1->next;
                   tem2=pHead_2->next->next;
                   pHead_1->next=pHead_2->next;
                   pHead_2->next->next=tem1;
                   pHead_2->next=tem2;
               }
           }*/
