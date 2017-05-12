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
        printf("��¼��ѧ��������: ");
        scanf("%s",pNew->name);
        printf("\n������ѧ���Ա�");
        scanf("%s",pNew->sex);
        printf("�༶��");
        scanf("%s",pNew->Class);
        printf("��ֱ�������Ƴɼ���\n");
        while(1)
        {
            printf("��ѧ��");
            scanf("%d",&pNew->Math);
            if(pNew->Math>=0&&pNew->Math<=150)
                break;
            else
                printf("��������������������\n");
        }
        while(1)
        {
            printf("���ģ�");
            scanf("%d",&pNew->Chinese);
            if(pNew->Chinese>=0&&pNew->Chinese<=150)
                break;
            printf("��������������������\n");
        }
        while(1)
        {
            printf("Ӣ�");
            scanf("%d",&pNew->English);
            if(pNew->English>=0&&pNew->English<=150)
                break;
            printf("��������������������\n");
        }
        pNew->next=list->next;
        list->next=pNew;
        ++i;
        printf("����ɹ���\n");
        printf("�Ƿ������������?�������롰1�����������롰0��\n");
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
            printf("��������,����������\n");
        }
        printf("�������������롰1��,�������롰0��\n");
        while(1)
        {
            scanf("%d",&i);
            if(i==0)
                return;
            if(i==1)
                break;
            printf("��������,����������\n");
        }
    }
}
void Change(struct Stu *list)
{
    int i;
    char a[100];
    printf("������Ҫ�޸��ߵ�������");
    scanf("%s",a);
    list=list->next;
    while(list!=NULL)
    {
        if(strcmp(a,list->name)==0)
        {
            printf("1.������%s\t2.�Ա�%s\t3.�༶��%s\t4.��ѧ��%d\t5.���ģ�%d\t6.Ӣ�%d\n",
                   list->name,list->sex,list->Class,list->Math,list->Chinese,list->English);
            printf("0.�˳��޸�������\n");
            while(scanf("%d",&i)!=EOF)
            {
                if(i==0)
                    return;
                if(i==1)
                {
                    printf("�����޸�Ϊ��");
                    scanf("%s",list->name);
                }
                else if(i==2)
                {
                    printf("�Ա��޸�Ϊ��");
                    scanf("%s",list->sex);
                }
                else if(i==3)
                {
                    printf("�༶�޸ģ�");
                    scanf("%s",list->Class);
                }
                else if(i==4)
                {
                    printf("��ѧ�޸�Ϊ��");
                    scanf("%d",&list->Math);
                }
                else if(i==5)
                {
                    printf("�����޸�Ϊ��");
                    scanf("%d",&list->Chinese);
                }
                else if(i==6)
                {
                    printf("Ӣ���޸�Ϊ��");
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
    printf("������Ҫɾ���ߵ�������");
    scanf("%s",a);
    while(list->next!=NULL)
    {
        if(strcmp(a,list->next->name)==0)
        {
            printf("������%s\t�Ա�%s\t�༶:%s\t��ѧ��%d\t���ģ�%d\tӢ�%d\n",
                   list->next->name,list->next->sex,list->next->Class,list->next->Math,list->next->Chinese,list->next->English);
            printf("�˶���Ϣ��ȷ�����䡰1����ȡ�����䡰0��\n");
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
    printf("������%s\t�Ա�%s\t�༶: %s\t��ѧ��%d\t���ģ�%d\tӢ�%d\n",
           list->name,list->sex,list->Class,list->Math,list->Chinese,list->English);
}
void Search(struct Stu *list)
{
    struct Stu *pTai;
    int i,r;
    char a[100];
    printf("��������,�༶����ѧ���������ķ�����Ӣ���������\n�ֱ�����:1, 2,3,4,5\n");
    list=list->next;
    pTai=list;
    scanf("%d",&i);
    if(i==1)
    {
        printf("������Ҫ�޸��ߵ�������");
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
        printf("������Ҫ�����ߵİ༶��");
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
        printf("������Ҫ�����ߵ���ѧ������");
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
        printf("������Ҫ�����ߵ����ķ�����");
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
        printf("������Ҫ�����ߵ�Ӣ�������");
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
    printf("�Ƿ������������?�������롰1�����������롰0��\n");
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
        printf("��������,����������\n");
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
    printf("���� 1.��ѧ������2.����������3.Ӣ��������0.�˳�����\n");
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
            printf("������%s\t�Ա�%s\t��ѧ��%d\t���ģ�%d\tӢ�%d\n",
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
            printf("������%s\t�Ա�%s\t��ѧ��%d\t���ģ�%d\tӢ�%d\n",
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
            printf("������%s\t�Ա�%s\t��ѧ��%d\t���ģ�%d\tӢ�%d\n",
                   pNew->name,pNew->sex,pNew->Math,pNew->Chinese,pNew->English);
            pNew=pNew->next;
        }
    }
    printf("�Ƿ������������?�������롰1�����������롰0��\n");
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
        printf("��������,����������\n");
    }
    printf("����������������롰1��,�������롰0��\n");
    while(1)
    {
        scanf("%d",&i);
        if(i==0)
            return;
        if(i==1)
            Order(list);
        printf("��������,����������\n");
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
    printf("\t\t\t\t �������\n\n");
    printf("\t\t\t���ڱ����ڶ�ʱ�����ٳɣ�\n\n\n\t\t  ȫ���벻����400��,�����밴ָ������\n\n\n\t\t\t     �������Ը�");
    getchar();
    system("cls");
}
void magezine()
{
    printf("\n\n\n");
    printf("\t����������������������������������������������������������\t\n");
    printf("\t��                                                      ��\t\n");
    printf("\t��                     1.�������                       ��\t\n");
    printf("\t��                                                      ��\t\n");
    printf("\t��                     2.��ӡ����                       ��\t\n");
    printf("\t��                                                      ��\t\n");
    printf("\t��                     3.���Ĳ���                       ��\t\n");
    printf("\t��                                                      ��\t\n");
    printf("\t��                     4.�������                       ��\t\n");
    printf("\t��                                                      ��\t\n");
    printf("\t��                     5.��������                       ��\t\n");
    printf("\t��                                                      ��\t\n");
    printf("\t��                     6.ɾ������                       ��\t\n");
    printf("\t��                                                      ��\t\n");
    printf("\t��                     0.�˳�����                       ��\t\n");
    printf("\t��                                                      ��\t\n");
    printf("\t����������������������������������������������������������\t\n");
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
                printf("\n\n\t\t���������������� 0\n");
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
                printf("\n\n\t\t���������������� 0\n");
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
                printf("\n\n\t\t���������������� 0\n");
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
                printf("\n\n\t\t���������������� 0\n");
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
                printf("\n\n\t\t���������������� 0\n");
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
