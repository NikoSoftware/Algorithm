#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
struct student    //�ṹ�嶨��
{
    int num;
    char name[10];
    char birthday[10];
    int Cyuyan;
    int shujujiegou;
    struct student *next;
};
struct student *creat_by_input();
struct student *get_last_student(struct student *head);
struct student *Print_menu_main()   //���˵�
{
    printf("  *********************************************************************\n");
    printf("                       | 1.........����ѧ����Ϣ   |                  \n");
    printf("                       | 2.........���ѧ����Ϣ   |                 \n");
    printf("                       | 3.........����ѧ����Ϣ   |                 \n");
    printf("                       | 4.........�޸�ѧ����Ϣ   |                 \n");
    printf("                       | 5.........����ѧ����Ϣ   |                 \n");
    printf("                       | 6.........ɾ��ѧ����Ϣ   |                 \n");
    printf("                       | 7.........����ѧ����Ϣ   |                 \n");
    printf("                       | 0.........�˳�ϵͳ       |                 \n");
    printf("                       |_ _ _ _ _ _ _ _ _ _ _ _ _ |                 \n");
}
struct student *print_table_head()
{
    printf("+----------+----------+----------+----------+-------------+\n");
    printf("|   ѧ��   |   ����   | �������� |  c�ɼ�   |���ݽṹ�ɼ� |\n");
    printf("+----------+----------+----------+----------+-------------+\n");
}
struct student  *print_table_row(struct student *p)
{
    printf("|%10d|%10s|%10s|%10d|%10d|\n",p->num,p->name,p->birthday,p->Cyuyan,p->shujujiegou);
}
void print_table_bottom()
{
    printf("+----------+----------+----------+----------+-------------+\n");
}
struct student * Creat_stu_record() //��������
{
    struct student *plaststu=NULL,*pnewstu;
    char continue_input='N';
    struct student *head=NULL;
    while(1)
    {
        if(head==NULL)
        {
            head=creat_by_input();
            print_table_head();
            print_table_row(head);
            print_table_bottom();
        }
        else
        {
            pnewstu=creat_by_input();
            print_table_head();
            print_table_row(pnewstu);
            print_table_bottom();
            plaststu=get_last_student(head);
            plaststu->next=pnewstu;
        }
        printf("�Ƿ��������ѧ����Ϣ��(Y ������N ���ز˵�)\n");
        getchar();
        continue_input=getchar();
        if(continue_input=='n'||continue_input=='N')
        {
            system("cls");
            Print_menu_main();
            break;
        }
    }
    return head;
}
struct student *creat_by_input()
{
    struct student *pnewstu=(struct student *)malloc(sizeof(struct student));
    printf("������ѧ����Ϣ\n");
    printf("ѧ��:");
    scanf("%d",&pnewstu->num);
    printf("����:");
    scanf("%s",pnewstu->name);
    printf("��������:");
    scanf("%s",pnewstu->birthday);
    printf("������ѧ���ɼ�\n");
    printf("C����:");
    scanf("%d",&(pnewstu->Cyuyan));
    printf("���ݽṹ:");
    scanf("%d",&(pnewstu->shujujiegou));
    pnewstu->next=NULL;
    return pnewstu;
}
struct student *get_last_student(struct student *p )
{
    if(p->next==NULL)
        return p;
    else
        return get_last_student(p->next);
}
void Print_Stu_Doc(struct student *head)
{
    struct student *p;
    char r;
    print_table_head();
    if(head==NULL)
    {
        printf("\n No Records\n");
    }
    for(p=head; p; p=p->next)
    {
        printf("|%10d|%10s|%10s|%10d|%10d|\n",p->num,p->name,p->birthday,p->Cyuyan,p->shujujiegou);
        printf("+----------+----------+----------+----------+-------------+\n");
    }
    printf("(��Enter���������˵�)\n");
    getchar();
    r=getchar();
    if(r!='1')
    {
        system("cls");
        Print_menu_main();
    }
    else
    {
        system("cls");
        Print_menu_main();
    }
}
struct student *search_by_name(struct student *head)//����������
{
    char name[10];
    struct student *p=head;
    char continue_input;  /*int isfound=0;*/
    printf("������Ҫ���ҵ�������");
    scanf("%s",name);
    printf("����%s\n",name);
    print_table_head();
    while(p!=NULL)
    {
        if(strcmp(p->name,name)==0)
        {
            print_table_row(p);
            p=p->next;  /* isfound=1; */
            break;
        }
        p=p->next;
    }
    print_table_bottom();
    printf("�Ƿ��������?(Y ������N �������˵�)\n");
    getchar();
    continue_input=getchar();
    if(continue_input=='n'||continue_input=='N')
    {
        system("cls");
        Print_menu_main();
    }
    else
        search_by_name(head);
}
struct student * search_by_id(struct student *head)//��ѧ�Ų���
{
    int id;
    struct student *p=head;
    char continue_input;  /*int isfound=0;*/
    printf("������Ҫ���ҵ�ѧ�ţ�");
    scanf("%d",&id);
    printf("����%d\n",id);
    print_table_head();
    while(p!=NULL)
    {
        if(p->num==id)
        {
            print_table_row(p);
            p=p->next;    /*isfound=1;*/
            break;
        }
        p=p->next;
    }
    print_table_bottom();
    printf("�Ƿ�������ң�(Y ������N �������˵�)\n");
    getchar();
    continue_input=getchar();
    if(continue_input=='n'||continue_input=='N')
    {
        system("cls");
        Print_menu_main();
    }
    else
        search_by_id(head);
    return head;
}
struct student*modify_record_by_id(struct student*head)//��ѧ���޸�
{
    struct student *p=head;
    int id;
    char continue_input;
    printf("������Ҫ�޸ĵ�ѧ����ѧ�ţ�\n");
    scanf("%d",&id);
    while(p!=NULL)
    {
        if(p->num==id)
            break;
        p=p->next;
    }
    if(p==NULL)
        printf("��Ǹ��û��ѧ��Ϊ%d��ѧ��\n",id);
    else
    {
        printf("������ѧ����Ϣ:\n");
        printf("ѧ��:");
        scanf("%d",&(p->num));
        printf("����:");
        scanf("%s",&(p->name));
        printf("��������:");
        scanf("%s",&(p->birthday));
        printf("������ѧ���ɼ���\n");
        printf("C����:");
        scanf("%d",&(p->Cyuyan));
        printf("���ݽṹ:");
        scanf("%d",&(p->shujujiegou));
        print_table_head();
        print_table_row(p);
        print_table_bottom();
    }
    printf("�����޸�ѧ����Ϣ��?Y  ������N �������˵�\n");
    getchar();
    continue_input=getchar();
    if(continue_input=='y'||continue_input=='Y')
        creat_by_input();
    else
    {
        system("cls");
        Print_menu_main();
    }
    return head;
}
struct student*modify_record_by_name(struct student*head)//�������޸�
{
    struct student*p=head;
    char name[10];
    char continue_input;
    printf("������Ҫ�޸ĵ�ѧ����������\n");
    scanf("%s",name);
    while(p!=NULL)
    {
        if(strcmp(p->name,name)==0)
            break;
        p=p->next;
    }
    if(p==NULL)
        printf("��Ǹ��û������Ϊ%s��ѧ��\n",name);
    else
    {
        printf("������ѧ����Ϣ:\n");
        printf("ѧ��:");
        scanf("%d",&(p->num));
        printf("����:");
        scanf("%s",&(p->name));
        printf("��������:");
        scanf("%s",&(p->birthday));
        printf("������ѧ���ɼ���\n");
        printf("C����:");
        scanf("%d",&(p->Cyuyan));
        printf("���ݽṹ:");
        scanf("%d",&(p->shujujiegou));
        print_table_head();
        print_table_row(p);
        print_table_bottom();
    }
    printf("�����޸�ѧ����Ϣ��?Y  ������N �������˵�\n");
    getchar();
    continue_input=getchar();
    if(continue_input=='y'||continue_input=='Y')
        creat_by_input();
    else
    {
        system("cls");
        Print_menu_main();
    }
    return head;
}
struct student *insert_record(struct student *head)//����
{
    struct student *ptr1;
    struct student *ptr,*stud;
    struct student *ptr2=head;
    char continue_input='N';
    int id;
    printf("������һ��ѧ�ţ��ڴ�֮ǰ����ѧ����Ϣ:");
    scanf("%d",&id);
    stud=creat_by_input();
    ptr=stud;
    if(head==NULL)
    {
        head=ptr;
        head->next=NULL;
    }
    else if(head->num==id)
    {
        ptr->next=head;
        head=ptr;
    }
    else
    {
        while(ptr2!=NULL)
        {
            ptr1=ptr2;
            ptr2=ptr1->next;
            if(ptr2->num==id)
            {
                ptr1->next=ptr;
                ptr->next=ptr2;
                break;
            }
        }
    }
    print_table_head();
    print_table_row(ptr);
    print_table_bottom();
    printf("�Ƿ��������ѧ����Ϣ?(Y ���� N �������˵�)\n");
    getchar();
    continue_input=getchar();
    if(continue_input=='y'||continue_input=='Y')
        return insert_record(head);
    else
    {
        system("cls");
        Print_menu_main();
        return head;
    }
}
struct student *Delete_record_by_id( struct student *head)//��ѧ��ɾ��
{
    struct student *p=head,*ppre=NULL;
    int id;
    char continue_input;
    printf("������Ҫɾ����ѧ��:");
    scanf("%d",&id);
    while(p!=NULL)
    {
        if(p->num==id)
            break;
        p=p->next;
    }
    if(p==NULL)
        printf("��Ǹ��û�и�ѧ�ŵ�ѧ����Ϣ��\n");
    else
    {
        printf("ȷ��Ҫɾ��ѧ��Ϊ%d��ѧ������Ϣ�𣿣�Y ȷ����N �������˵���\n",p->num);
        getchar();

        continue_input=getchar();
        if(continue_input=='y'||continue_input=='Y')
        {
            ppre=head;
            if(ppre==p)
            {
                head=p->next;
                printf("         \n");
                free(p);
            }
            else
            {
                while(ppre!=NULL)
                {
                    if(ppre->next==p)
                    {
                        ppre->next=p->next;
                        free(p);
                        break;
                    }
                    ppre=ppre->next;
                }
            }
            printf("ɾ���ɹ���");
        }
        // Print_menu_main();
    }
    printf("����ɾ��ѧ����Ϣ��(Y ������N �������˵�)");
    getchar();
    continue_input=getchar();
    if(continue_input=='y'||continue_input=='Y')
        Delete_record_by_id(head);
    else
    {
        system("cls");
        Print_menu_main();
        return head;
    }
    return 0;
}
struct student *Delete_record_by_name( struct student *head)// ������ɾ��
{
    struct student *p=head,*ppre=NULL;
    char name[10];
    char continue_input;
    printf("������Ҫɾ��������:");
    scanf("%s",name);
    while(p!=NULL)
    {
        if(strcmp(p->name,name)==0) break;
        p=p->next;
    }
    if(p==NULL)
    {
        printf("��Ǹ��û�и�������ѧ����Ϣ��\n");
        goto end;
    }
    else
        printf("ȷ��Ҫɾ������Ϊ%s��ѧ������Ϣ�𣿣�Y ȷ����N �������˵���",p->name);
    printf("\n");
    getchar();
    continue_input=getchar();
    if(continue_input=='y'||continue_input=='Y')
    {
        ppre=head;
        if(ppre==p)
        {
            head=p->next;
            free(p);
        }
        else
        {
            while(ppre!=NULL)
            {
                if(ppre->next==p)
                {
                    ppre->next=p->next;
                    free(p);
                    break;
                }
                ppre=ppre->next;
            }
        }
        printf("ɾ���ɹ���");
    }
//else Print_menu_main();
end:
    printf("����ɾ��ѧ����Ϣ��(Y ������N �������˵�)");
    printf("\n");
    getchar();
    continue_input=getchar();
    if(continue_input=='Y'||continue_input=='y')
        Delete_record_by_name(head);
    else
    {
        system("cls");
        Print_menu_main();
        return head;
    }
    return 0;
}
struct student * Sorting_record_by_id(struct student *head)//��ѧ������
{
    int i=0,j,k,r;
    struct student *pt1,*pt2,*pt,m;
    if(head==NULL)
    {
        printf("������ͬѧ��¼\n");
        printf("(��Enter���������˵�)\n");
        getchar();
        r=getchar();
        if(r!='1')
        {
            system("cls");
            Print_menu_main();
        }
        else
        {
            system("cls");
            Print_menu_main();
        }
    }
    else
    {
        pt1=head;
        pt2=head->next;
        for(pt=head; pt; pt=pt->next)    i++;
        for(j=1; j<i; j++)
        {
            pt1=head;
            pt2=head->next;
            for(k=1; k<i-j+1; k++)
            {
                if(pt1->num>pt2->num)
                {
                    m=*pt1;
                    *pt1=*pt2;
                    *pt2=m;
                    pt2->next=pt1->next;
                    pt1->next=pt2;
                }
                pt1=pt2;
                pt2=pt1->next;
            }
        }
    }
    print_table_head();
    for(pt=head; pt; pt=pt->next)
        printf("|%10d|%10s|%10s|%10d|%10d|\n",pt->num,pt->name,pt->birthday,pt->Cyuyan,pt->shujujiegou);
    printf("+----------+----------+----------+----------+----------+\n");
    return head;
}
int main()
{
    struct student *head=NULL;
    struct student *p;
    int choice;
    int select;
    char m;
    char r;
    system("color e");
    printf("                                                                               \n");
    printf("                                                                               \n");
    printf("                           ��ӭʹ��ѧ���ɼ�����ϵͳ��                  \n");
    printf("                                                                               \n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("                                                                               \n");
    printf("...............................................................................\n");
    printf("�밴����ʾ��Ϣ��ɲ���\n");
    Print_menu_main();
    printf("                                                                               \n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("                                                                               \n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");

    while(choice!=0)
    {
        printf("��ѡ����Ҫִ�еĲ�����\n");
start:
        if(scanf("%d",&choice))
        {
            if(choice>7||choice<0)
            {
                printf("������0��7������,ѡ����Ҫִ�еĲ�����\n");
                goto start;
            }
            else
                goto next;
        }
        if(scanf("%c",&m))
        {
            printf("������0��7������,ѡ����Ҫִ�еĲ�����\n");
            goto start;
        }
next:
        switch(choice)
        {
        case 1:
            system("cls");
            head=Creat_stu_record();
            break;
        case 2:
            system("cls");
            Print_Stu_Doc(head);
            break;
        case 3:
            system("cls");
            printf("��ѡ����ҷ�ʽ��1 ���������ң� 2 ��ѧ�Ų��ң�3 �������˵�");
            printf("\n");
            scanf("%d",&select);
            switch(select)
            {
            case 1:
                search_by_name(head);
                break;
            case 2:
                search_by_id(head);
                break;
            case 3:
                system("cls");
                Print_menu_main();
                break;
            };
            break;
        case 4:
            system("cls");
            printf("�������޸ķ�ʽ��1 ��ѧ���޸ģ�2 �������޸�; 3 �������˵�");
            printf("\n");
            scanf("%d",&select);
            switch(select)
            {
            case 1:
                system("cls");
                modify_record_by_id(head);
                break;
            case 2:
                system("cls");
                modify_record_by_name(head);
                break;
            case 3:
                system("cls");
                Print_menu_main();
                break;
            }
            break;
        case 5:
            system("cls");
            head=insert_record(head);
            break;
        case 6:
            system("cls");
            printf("������ɾ����ʽ��1 ��ѧ��ɾ����2 ������ɾ��; 3 �������˵�\n");
            scanf("%d",&select);
            switch(select)
            {
            case 1:
                head=Delete_record_by_id(head);
                break;
            case 2:
                head=Delete_record_by_name(head);
                break;
            case 3:
                Print_menu_main();
                break;
            }
            break;
        case 7:
            system("cls");
            Sorting_record_by_id(head);
            printf("(��Enter���������˵�)\n");
            getchar();
            r=getchar();
            if(r!='1')
            {
                system("cls");
                Print_menu_main();
            }
            else
            {
                system("cls");
                Print_menu_main();
            }
            break;
            break;
        case 0:
            system("cls");
            printf("                                                            \n");
            printf("------------------------------------------------------------\n");
            printf(" ^-^  ^-^  ^-^  ^-^  ^-^  ллʹ�� ^-^  ^-^  ^-^  ^-^  ^-^��\n");
            printf("                                                            \n");
            break;

        }
    }
}
