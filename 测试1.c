#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
struct student    //结构体定义
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
struct student *Print_menu_main()   //主菜单
{
    printf("  *********************************************************************\n");
    printf("                       | 1.........输入学生信息   |                  \n");
    printf("                       | 2.........输出学生信息   |                 \n");
    printf("                       | 3.........查找学生信息   |                 \n");
    printf("                       | 4.........修改学生信息   |                 \n");
    printf("                       | 5.........插入学生信息   |                 \n");
    printf("                       | 6.........删除学生信息   |                 \n");
    printf("                       | 7.........排序学生信息   |                 \n");
    printf("                       | 0.........退出系统       |                 \n");
    printf("                       |_ _ _ _ _ _ _ _ _ _ _ _ _ |                 \n");
}
struct student *print_table_head()
{
    printf("+----------+----------+----------+----------+-------------+\n");
    printf("|   学号   |   姓名   | 出生日期 |  c成绩   |数据结构成绩 |\n");
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
struct student * Creat_stu_record() //建立链表
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
        printf("是否继续输入学生信息？(Y 继续，N 返回菜单)\n");
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
    printf("请输入学生信息\n");
    printf("学号:");
    scanf("%d",&pnewstu->num);
    printf("姓名:");
    scanf("%s",pnewstu->name);
    printf("出生年月:");
    scanf("%s",pnewstu->birthday);
    printf("请输入学生成绩\n");
    printf("C语言:");
    scanf("%d",&(pnewstu->Cyuyan));
    printf("数据结构:");
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
    printf("(按Enter键返回主菜单)\n");
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
struct student *search_by_name(struct student *head)//按姓名查找
{
    char name[10];
    struct student *p=head;
    char continue_input;  /*int isfound=0;*/
    printf("请输入要查找的姓名：");
    scanf("%s",name);
    printf("查找%s\n",name);
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
    printf("是否继续查找?(Y 继续；N 返回主菜单)\n");
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
struct student * search_by_id(struct student *head)//按学号查找
{
    int id;
    struct student *p=head;
    char continue_input;  /*int isfound=0;*/
    printf("请输入要查找的学号：");
    scanf("%d",&id);
    printf("查找%d\n",id);
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
    printf("是否继续查找？(Y 继续；N 返回主菜单)\n");
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
struct student*modify_record_by_id(struct student*head)//按学号修改
{
    struct student *p=head;
    int id;
    char continue_input;
    printf("请输入要修改的学生的学号：\n");
    scanf("%d",&id);
    while(p!=NULL)
    {
        if(p->num==id)
            break;
        p=p->next;
    }
    if(p==NULL)
        printf("抱歉，没有学号为%d的学生\n",id);
    else
    {
        printf("请输入学生信息:\n");
        printf("学号:");
        scanf("%d",&(p->num));
        printf("姓名:");
        scanf("%s",&(p->name));
        printf("出生年月:");
        scanf("%s",&(p->birthday));
        printf("请输入学生成绩：\n");
        printf("C语言:");
        scanf("%d",&(p->Cyuyan));
        printf("数据结构:");
        scanf("%d",&(p->shujujiegou));
        print_table_head();
        print_table_row(p);
        print_table_bottom();
    }
    printf("继续修改学生信息吗?Y  继续；N 返回主菜单\n");
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
struct student*modify_record_by_name(struct student*head)//按姓名修改
{
    struct student*p=head;
    char name[10];
    char continue_input;
    printf("请输入要修改的学生的姓名：\n");
    scanf("%s",name);
    while(p!=NULL)
    {
        if(strcmp(p->name,name)==0)
            break;
        p=p->next;
    }
    if(p==NULL)
        printf("抱歉，没有姓名为%s的学生\n",name);
    else
    {
        printf("请输入学生信息:\n");
        printf("学号:");
        scanf("%d",&(p->num));
        printf("姓名:");
        scanf("%s",&(p->name));
        printf("出生年月:");
        scanf("%s",&(p->birthday));
        printf("请输入学生成绩：\n");
        printf("C语言:");
        scanf("%d",&(p->Cyuyan));
        printf("数据结构:");
        scanf("%d",&(p->shujujiegou));
        print_table_head();
        print_table_row(p);
        print_table_bottom();
    }
    printf("继续修改学生信息吗?Y  继续；N 返回主菜单\n");
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
struct student *insert_record(struct student *head)//插入
{
    struct student *ptr1;
    struct student *ptr,*stud;
    struct student *ptr2=head;
    char continue_input='N';
    int id;
    printf("请输入一个学号，在此之前插入学生信息:");
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
    printf("是否继续插入学生信息?(Y 继续 N 返回主菜单)\n");
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
struct student *Delete_record_by_id( struct student *head)//按学号删除
{
    struct student *p=head,*ppre=NULL;
    int id;
    char continue_input;
    printf("请输入要删除的学号:");
    scanf("%d",&id);
    while(p!=NULL)
    {
        if(p->num==id)
            break;
        p=p->next;
    }
    if(p==NULL)
        printf("抱歉，没有该学号的学生信息！\n");
    else
    {
        printf("确定要删除学号为%d的学生的信息吗？（Y 确定；N 返回主菜单）\n",p->num);
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
            printf("删除成功！");
        }
        // Print_menu_main();
    }
    printf("继续删除学生信息吗？(Y 继续；N 返回主菜单)");
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
struct student *Delete_record_by_name( struct student *head)// 按姓名删除
{
    struct student *p=head,*ppre=NULL;
    char name[10];
    char continue_input;
    printf("请输入要删除的姓名:");
    scanf("%s",name);
    while(p!=NULL)
    {
        if(strcmp(p->name,name)==0) break;
        p=p->next;
    }
    if(p==NULL)
    {
        printf("抱歉，没有该姓名的学生信息！\n");
        goto end;
    }
    else
        printf("确定要删除姓名为%s的学生的信息吗？（Y 确定；N 返回主菜单）",p->name);
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
        printf("删除成功！");
    }
//else Print_menu_main();
end:
    printf("继续删除学生信息吗？(Y 继续；N 返回主菜单)");
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
struct student * Sorting_record_by_id(struct student *head)//按学号排序
{
    int i=0,j,k,r;
    struct student *pt1,*pt2,*pt,m;
    if(head==NULL)
    {
        printf("现在无同学记录\n");
        printf("(按Enter键返回主菜单)\n");
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
    printf("                           欢迎使用学生成绩管理系统！                  \n");
    printf("                                                                               \n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("                                                                               \n");
    printf("...............................................................................\n");
    printf("请按照提示信息完成操作\n");
    Print_menu_main();
    printf("                                                                               \n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("                                                                               \n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");

    while(choice!=0)
    {
        printf("请选择所要执行的操作：\n");
start:
        if(scanf("%d",&choice))
        {
            if(choice>7||choice<0)
            {
                printf("请输入0到7的数字,选择所要执行的操作：\n");
                goto start;
            }
            else
                goto next;
        }
        if(scanf("%c",&m))
        {
            printf("请输入0到7的数字,选择所要执行的操作：\n");
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
            printf("请选择查找方式：1 按姓名查找； 2 按学号查找；3 返回主菜单");
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
            printf("请输入修改方式：1 按学号修改；2 按姓名修改; 3 返回主菜单");
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
            printf("请输入删除方式：1 按学号删除；2 按姓名删除; 3 返回主菜单\n");
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
            printf("(按Enter键返回主菜单)\n");
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
            printf(" ^-^  ^-^  ^-^  ^-^  ^-^  谢谢使用 ^-^  ^-^  ^-^  ^-^  ^-^！\n");
            printf("                                                            \n");
            break;

        }
    }
}
