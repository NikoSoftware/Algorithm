#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n=0;
struct Stu
{
    char name[100];
    char sex[100];
    char Class[100];
    int Math,Chinese,English;
    struct Stu *next;
};
struct Stu *Init()
{
    struct Stu *pHead;
    pHead=(struct Stu *)malloc(sizeof(struct Stu));
    pHead->next=NULL;
    return pHead;
}
void Insert(struct Stu *list)
{
    int i;
    char a[100];
    while(1)
    {
        struct Stu *pNew;
        pNew=(struct Stu*)malloc(sizeof(struct Stu));
        pNew->Math=pNew->Chinese=pNew->English=-1;
        printf("请录入学生的姓名: ");
        scanf("%s",pNew->name);
        printf("\n请输入学生性别：");
        scanf("%s",pNew->sex);
        printf("班级：");
        scanf("%s",pNew->Class);
        printf("请分别输入各科成绩：\n");
        while(1)
        {
            printf("数学：");
            scanf("%d",&pNew->Math);
            if(pNew->Math>=0&&pNew->Math<=150)
                break;
            else
                printf("你输入有误请重新输入\n");
        }
        while(1)
        {
            printf("语文：");
            scanf("%d",&pNew->Chinese);
            if(pNew->Chinese>=0&&pNew->Chinese<=150)
                break;
            printf("你输入有误请重新输入\n");
        }
        while(1)
        {
            printf("英语：");
            scanf("%d",&pNew->English);
            if(pNew->English>=0&&pNew->English<=150)
                break;
            printf("你输入有误请重新输入\n");
        }
        pNew->next=list->next;
        list->next=pNew;
        ++i;
        printf("插入成功！\n");
        printf("是否进行清屏操作?是请输入“1”，否请输入“0”\n");
        while(1)
        {
            scanf("%d",&i);
            if(i==0)
                return;
            if(i==1)
            {
                system("cls");
                break;
            }
            printf("输入有误,请重新输入\n");
        }
        printf("继续插入请输入“1”,否则输入“0”\n");
        while(1)
        {
            scanf("%d",&i);
            if(i==0)
                return;
            if(i==1)
                break;
            printf("输入有误,请重新输入\n");
        }
    }
}
void Change(struct Stu *list)
{
    int i;
    char a[100];
    printf("请输入要修改者的姓名：");
    scanf("%s",a);
    list=list->next;
    while(list!=NULL)
    {
        if(strcmp(a,list->name)==0)
        {
            printf("1.姓名：%s\t2.性别：%s\t3.班级：%s\t4.数学：%d\t5.语文：%d\t6.英语：%d\n",
                   list->name,list->sex,list->Class,list->Math,list->Chinese,list->English);
            printf("0.退出修改请输入\n");
            while(scanf("%d",&i)!=EOF)
            {
                if(i==0)
                    return;
                if(i==1)
                {
                    printf("姓名修改为：");
                    scanf("%s",list->name);
                }
                else if(i==2)
                {
                    printf("性别修改为：");
                    scanf("%s",list->sex);
                }
                else if(i==3)
                {
                    printf("班级修改：");
                    scanf("%s",list->Class);
                }
                else if(i==4)
                {
                    printf("数学修改为：");
                    scanf("%d",&list->Math);
                }
                else if(i==5)
                {
                    printf("语文修改为：");
                    scanf("%d",&list->Chinese);
                }
                else if(i==6)
                {
                    printf("英语修改为：");
                    scanf("%d",&list->English);
                }
            }
        }
        list=list->next;
    }
}
void Del(struct Stu *list)
{
    int i;
    char a[100];
    printf("请输入要删除者的姓名：");
    scanf("%s",a);
    while(list->next!=NULL)
    {
        if(strcmp(a,list->next->name)==0)
        {
            printf("姓名：%s\t性别：%s\t班级:%s\t数学：%d\t语文：%d\t英语：%d\n",
                   list->next->name,list->next->sex,list->next->Class,list->next->Math,list->next->Chinese,list->next->English);
            printf("核对信息，确认请输“1”，取消请输“0”\n");
            scanf("%d",&i);
            if(i==0)
                return;
            free(list->next);
            list->next=list->next->next;
            --i;
        }
        list=list->next;
    }
}
void Magezine(struct Stu *list)
{
    printf("姓名：%s\t性别：%s\t班级: %s\t数学：%d\t语文：%d\t英语：%d\n",
           list->name,list->sex,list->Class,list->Math,list->Chinese,list->English);
}
void Search(struct Stu *list)
{
    struct Stu *pTai;
    int i,r;
    char a[100];
    printf("进行名字,班级，数学分数，语文分数，英语分数搜索\n分别输入:1, 2,3,4,5\n");
    list=list->next;
    pTai=list;
    scanf("%d",&i);
    if(i==1)
    {
        printf("请输入要修改者的姓名：");
        scanf("%s",a);
        while(list!=NULL)
        {
            if(strcmp(a,list->name)==0)
            {
                Magezine(list);
            }
            list=list->next;
        }
        list=pTai;
    }
    else if(i==2)
    {
        printf("请输入要搜索者的班级：");
        scanf("%s",a);
        while(list!=NULL)
        {
            if(strcmp(a,list->Class)==0)
            {
                Magezine(list);
            }
            list=list->next;
        }
        list=pTai;
    }
    else if(i==3)
    {
        printf("请输入要搜索者的数学分数：");
        scanf("%d",&r);
        while(list!=NULL)
        {
            if(list->Math==r)
            {
                Magezine(list);
            }
            list=list->next;
        }
        list=pTai;
    }
    else if(i==4)
    {
        printf("请输入要搜索者的语文分数：");
        scanf("%d",&r);
        while(list!=NULL)
        {
            if(list->Chinese==r)
            {
                Magezine(list);
            }
            list=list->next;
        }
        list=pTai;
    }
    else if(i==5)
    {
        printf("请输入要搜索者的英语分数：");
        scanf("%d",&r);
        while(list!=NULL)
        {
            if(list->English==r)
            {
                Magezine(list);
            }
            list=list->next;
        }
        list=pTai;
    }
    printf("是否进行清屏操作?是请输入“1”，否请输入“0”\n");
    while(1)
    {
        scanf("%d",&i);
        if(i==0)
            return;
        if(i==1)
        {
            system("cls");
            break;
        }
        printf("输入有误,请重新输入\n");
    }
}

void jiaohuan(struct Stu *p,struct Stu *q)
{
    struct Stu *pTai;
    char a[100];
    pTai=(struct Stu*)malloc(sizeof(struct Stu));
    pTai->next=NULL;

    strcpy(a,p->name);
    strcpy(p->name,q->name);
    strcpy(q->name,a);

    strcpy(a,p->sex);
    strcpy(p->sex,q->sex);
    strcpy(q->sex,a);

    strcpy(a,p->Class);
    strcpy(p->Class,q->name);
    strcpy(q->Class,a);

    pTai->Math=p->Math;
    p->Math=q->Math;
    q->Math=pTai->Math;

    pTai->Chinese=p->Chinese;
    p->Chinese=q->Chinese;
    q->Chinese=pTai->Chinese;

    pTai->English=p->English;
    p->English=q->English;
    q->English=pTai->English;
}


//
void Order(struct Stu *list)
{
    int i,j,t,c;
    struct Stu *p,*q,*pNew=list->next;
    struct Stu *pTai;
    pTai=(struct Stu*)malloc(sizeof(struct Stu));
    printf("输入 1.数学排名，2.语文排名，3.英语排名，0.退出操作\n");
    scanf("%d",&i);
    if(i==0)
        return;
    if(i==1)
    {
        for(i=0,p=list->next; i<n-1; i++,p=p->next)
            for(j=i+1,q=p->next; j<n; j++,q=p->next)
            {
                if(p->Math>q->Math)
                {
                    jiaohuan(p,q);
                }
            }
        while(pNew!=NULL)
        {
            printf("姓名：%s\t性别：%s\t数学：%d\t语文：%d\t英语：%d\n",
                   pNew->name,pNew->sex,pNew->Math,pNew->Chinese,pNew->English);
            pNew=pNew->next;
        }
    }
    if(i==2)
    {
        for(i=0,p=list->next; i<n-1; i++,p=p->next)
            for(j=i+1,q=p->next; j<n; j++,q=p->next)
            {
                if(p->Chinese>q->Chinese)
                {
                    jiaohuan(p,q);
                }
            }
        while(pNew!=NULL)
        {
            printf("姓名：%s\t性别：%s\t数学：%d\t语文：%d\t英语：%d\n",
                   pNew->name,pNew->sex,pNew->Math,pNew->Chinese,pNew->English);
            pNew=pNew->next;
        }
    }
    if(i==3)
    {
        for(i=0,p=list->next; i<n-1; i++,p=p->next)
            for(j=i+1,q=p->next; j<n; j++,q=p->next)
            {
                if(p->English>q->English)
                {
                    jiaohuan(p,q);
                }
            }
        while(pNew!=NULL)
        {
            printf("姓名：%s\t性别：%s\t数学：%d\t语文：%d\t英语：%d\n",
                   pNew->name,pNew->sex,pNew->Math,pNew->Chinese,pNew->English);
            pNew=pNew->next;
        }
    }
    printf("是否进行清屏操作?是请输入“1”，否请输入“0”\n");
    while(1)
    {
        scanf("%d",&i);
        if(i==0)
            return;
        if(i==1)
        {
            system("cls");
            break;
        }
        printf("输入有误,请重新输入\n");
    }
    printf("继续排序操作请输入“1”,否则输入“0”\n");
    while(1)
    {
        scanf("%d",&i);
        if(i==0)
            return;
        if(i==1)
            Order(list);
        printf("输入有误,请重新输入\n");
    }
}
void Display(struct Stu *list)
{
    list=list->next;
    while(list!=NULL)
    {
        puts("faf");
        Magezine(list);
        list=list->next;
    }
}
void Warn()
{
    printf("\t\t\t\t 软件警告\n\n");
    printf("\t\t\t由于本软在短时间内速成，\n\n\n\t\t  全代码不超过400行,所以请按指定输入\n\n\n\t\t\t     否则后果自负");
    getchar();
    system("cls");
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
    struct Stu *list;
    list=Init();
    while(1)
    {
        int i,j;
        magezine();
        scanf("%d",&i);
        if(i==1)
        {
            system("cls");
            Insert(list);
        }
        if(i==2)
        {
            system("cls");
            Display(list);
            while(1)
            {
                printf("\n\n\t\t还回主界面请输入 0\n");
                scanf("%d",&j);
                if(j==0)
                    break;
            }
        }
        if(i==3)
        {
            system("cls");
            Display(list);
            Change(list);
            while(1)
            {
                printf("\n\n\t\t还回主界面请输入 0\n");
                scanf("%d",&j);
                if(j==0)
                    break;
            }
        }
        if(i==4)
        {
            system("cls");
            Order(list);
            while(1)
            {
                printf("\n\n\t\t还回主界面请输入 0\n");
                scanf("%d",&j);
                if(j==0)
                    break;
            }
        }
        if(i==5)
        {
            system("cls");
            Search(list);
            while(1)
            {
                printf("\n\n\t\t还回主界面请输入 0\n");
                scanf("%d",&j);
                if(j==0)
                    break;
            }
        }
        if(i==6)
        {
            system("cls");
            Del(list);
            while(1)
            {
                printf("\n\n\t\t还回主界面请输入 0\n");
                scanf("%d",&j);
                if(j==0)
                    break;
            }
        }
        if(i==0)
        {
            break;
        }
        system("cls");
    }
}
