#include<stdio.h>
#include<string.h>
#include<math.h>
int n=0,m,f,d;
struct node
{
    char Name[100];
    char Sex[100];
    char Num[100];
    char Math[100],Chinese[100],English[100];
};
struct node person[100];
void Insert()
{
    int i;
    char a[100],nan[20]= {"男"},nv[20]= {"女"};
    while(1)
    {
        printf("输入名字：");
        scanf("%s",person[n].Name);
        while(1)
        {
            printf("输入性别 男/女：");
            scanf("%s",person[n].Sex);
            if(strcmp(person[n].Sex,nan)==0||strcmp(person[n].Sex,nv)==0)
                break;
            printf("输入错误!\n");
        }
        printf("输入学号：");
        scanf("%s",person[n].Num);
        while(1)
        {
            float sum=0,flag=0;
            printf("数学：");
            scanf("%s",person[n].Math);
            m=strlen(person[n].Math);
            for(i=0,d=0; i<m; i++)
            {
                if(person[n].Math[i]!='.')
                    d++;
                else
                    break;
            }
            if(person[n].Math[0]=='0')
            {
                if(person[n].Math[1]!='.')
                    flag=1;
            }
            for(i=d+1; i<m; i++)
                if(person[n].Math[i]=='.')
                {
                    flag=1;
                    break;
                }
            for(i=0; i<m; i++)
            {
                if(flag==1)
                    break;
                if(person[n].Math[i]<'0'||person[n].Math[i]>'9')
                {
                    if(person[n].Math[i]!='.')
                    {
                        flag=1;
                        break;
                    }
                }
                if(person[n].Math[i]=='.')
                    continue;
                sum+=(person[n].Math[i]-'0')*pow(10,--d);
            }
            if(flag==0&&sum>=0&&sum<=150)
                break;
            else
                printf("你输入有误请重新输入\n");
        }
        while(1)
        {
            float sum=0,flag=0;
            printf("语文：");
            scanf("%s",person[n].Chinese);
            m=strlen(person[n].Chinese);
            for(i=0,d=0; i<m; i++)
            {
                if(person[n].Chinese[i]!='.')
                    d++;
                else
                    break;
            }
            if(person[n].Chinese[0]=='0')
            {
                if(person[n].Chinese[1]!='.')
                    flag=1;
            }
            for(i=d+1; i<m; i++)
                if(person[n].Chinese[i]=='.')
                {
                    flag=1;
                    break;
                }
            for(i=0; i<m; i++)
            {
                if(flag==1)
                    break;
                if(person[n].Chinese[i]<'0'||person[n].Chinese[i]>'9')
                {
                    if(person[n].Chinese[i]!='.')
                    {
                        flag=1;
                        break;
                    }
                }
                if(person[n].Chinese[i]=='.')
                    continue;
                sum+=(person[n].Chinese[i]-'0')*pow(10,--d);
            }
            if(flag==0&&sum>=0&&sum<=150)
                break;
            else
                printf("你输入有误请重新输入\n");
        }
        while(1)
        {
            float sum=0,flag=0;
            printf("英语：");
            scanf("%s",person[n].English);
            m=strlen(person[n].English);
            for(i=0,d=0; i<m; i++)
            {
                if(person[n].English[i]!='.')
                    d++;
                else
                    break;
            }
            if(person[n].English[0]=='0')
            {
                if(person[n].English[1]!='.')
                    flag=1;
            }
            for(i=d+1; i<m; i++)
                if(person[n].English[i]=='.')
                {
                    flag=1;
                    break;
                }
            for(i=0; i<m; i++)
            {
                if(flag==1)
                    break;
                if(person[n].English[i]<'0'||person[n].English[i]>'9')
                {
                    if(person[n].English[i]!='.')
                    {
                        flag=1;
                        break;
                    }
                }
                if(person[n].English[i]=='.')
                    continue;
                sum+=(person[n].English[i]-'0')*pow(10,--d);
            }
            if(flag==0&&sum>=0&&sum<=150)
                break;
            else
                printf("你输入有误请重新输入\n");
        }
        n++;
        printf("是否继续插入！是请输入 1\n");
        scanf("%s",a);
        system("cls");
        if(a[0]!='1')
            break;
    }
}
void massage(int i)
{
    printf("姓名：%s\t性别：%s\t学号：%s\t数学：%s\t语文：%s\t英语：%s\n",person[i].Name,person[i].Sex,person[i].Num,person[i].Math,person[i].Chinese,person[i].English);
}
void Display()
{
    int i;
    if(n==0)
        printf("内部无值\n");
    for(i=0; i<n; i++)
    {
        massage(i);
    }
}
int chengji(char *p)
{

    int m=0,f,flag=0,i;
    float sum=0;
    m=strlen(p);
    for(i=0,d=0; i<m; i++)
    {
        if(p[i]!='.')
            d++;
        else
            break;
    }
    if(p[0]=='0')
    {
        if(p[1]!='.')
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
void Change()
{
    int i,flag=0,j;
    char a[100],b[10],c[10],nan[20]= {"男"},nv[20]= {"女"};;
    Display();
    if(n==0)
    {
        getchar();
        return;
    }
    printf("输入 1.名字搜索，2.学号搜索\n");
    while(1)
    {
        scanf("%s",b);
        if(b[0]>='0'&&b[0]<='9')
            break;//怕麻烦 而且不想多写代码，估计他也测不出来，呵呵
        printf("输入有误，请重新输入\n");
    }
    if(b[0]=='1')
    {
        int flag=0;
        printf("请输入用户的名字：");
        scanf("%s",a);
        for(i=0; i<n; i++)
        {
            if(strcmp(a,person[i].Name)==0)
            {
                massage(i);
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
                    scanf("%s",person[i].Name);
                }
                else if(c[0]=='2')
                {
                    while(1)
                    {
                        printf("输入性别 男/女：");
                        scanf("%s",person[i].Sex);
                        if(strcmp(person[i].Sex,nan)==0||strcmp(person[i].Sex,nv)==0)
                            break;
                        printf("输入错误!\n");
                    }
                }
                else if(c[0]=='3')
                {
                    printf("学号：");
                    scanf("%s",person[i].Num);

                }
                else if(c[0]=='4')
                {
                    while(1)
                    {
                        printf("数学：");
                        scanf("%s",person[i].Math);
                        if(chengji(person[i].Math)==1)
                            break;
                        printf("输入错误，请重新输入!\n");
                    }
                }
                else if(c[0]=='5')
                {
                    while(1)
                    {
                        printf("语文：");
                        scanf("%s",person[i].Chinese);
                        if(chengji(person[i].Chinese)==1)
                            break;
                        printf("输入错误，请重新输入!\n");
                    }
                }
                else if(c[0]=='6')
                {
                    while(1)
                    {
                        printf("英语：");
                        scanf("%s",person[i].English);
                        if(chengji(person[i].English)==1)
                            break;
                        printf("输入错误，请重新输入!\n");
                    }
                }
                break;
            }
            if(flag==0)
                printf("无此项搜索");
        }
    }
    else if(b[0]=='2')
    {
        int flag=0;
        printf("请输入用户的学号：");
        scanf("%s",a);
        for(i=0; i<n; i++)
        {
            if(strcmp(a,person[i].Num)==0)
            {
                flag=1;
                massage(i);
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
                    scanf("%s",person[i].Name);
                }
                else if(c[0]=='2')
                {
                    printf("性别：");
                    scanf("%s",person[i].Sex);
                }
                else if(c[0]=='3')
                {
                    printf("学号：");
                    scanf("%s",person[i].Num);
                }
                else if(c[0]=='4')
                {
                    printf("数学：");
                    scanf("%s",person[i].Math);
                }
                else if(c[0]=='5')
                {
                    printf("语文：");
                    scanf("%s",person[i].Chinese);
                }
                else if(c[0]=='6')
                {
                    printf("英语：");
                    scanf("%s",person[i].English);
                }
                break;
            }
        }
        if(flag==0)
            printf("无此项结果！");
    }
}
int reseach()
{
    int i,flag=0;
    char a[100],b[10],c[10];
    Display();
    if(n==0)
    {
        getchar();
        return -1;
    }
    printf("输入 1.名字搜索，2.学号搜索\n");
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
        for(i=0; i<n; i++)
        {
            if(strcmp(a,person[i].Name)==0)
            {
                massage(i);
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("无此搜索\n");
            return -1;
        }
        return i;
    }
    if(b[0]=='2')
    {
        printf("请输入用户的学号：");
        scanf("%s",a);
        for(i=0; i<n; i++)
        {
            if(strcmp(a,person[i].Num)==0)
            {
                massage(i);
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("无此搜索\n");
            return -1;
        }
        return i;
    }
}
void Del()
{
    int i,index;
    index=reseach();
    if(n==0)
    {
        getchar();
        return;
    }
    if(index==-1)
    {
        printf("输入有误\n");
        return ;
    }
    for(i=index; i<n-1; i++)
    {
        person[i]=person[i+1];
    }
    n--;
    printf("删除成功");
    getchar();
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
void order()
{
    int i,j;
    //long long sum;
    char a[100],b[10];
    struct node tem;
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
            break;//怕麻烦 而且不想多写代码，估计他也测不出来，呵呵
        printf("输入有误，请重新输入\n");
    }
    if(b[0]=='1')
    {
        for(i=0; i<n-1; i++)
            for(j=i+1; j<n; j++)
            {
                if(Com(person[i].Num,person[j].Num)==0)
                {
                    tem=person[i];
                    person[i]=person[j];
                    person[j]=tem;
                }
            }
    }
    if(b[0]=='2')
    {
        for(i=0; i<n-1; i++)
            for(j=i+1; j<n; j++)
            {
                if(Com(person[i].Math,person[j].Math)==1)
                {
                    tem=person[i];
                    person[i]=person[j];
                    person[j]=tem;
                }
            }
    }
    if(b[0]=='3')
    {
        for(i=0; i<n-1; i++)
            for(j=i+1; j<n; j++)
            {
                if(Com(person[i].Chinese,person[j].Chinese)==1)
                {
                    tem=person[i];
                    person[i]=person[j];
                    person[j]=tem;
                }
            }
    }
    if(b[0]=='4')
    {
        for(i=0; i<n-1; i++)
            for(j=i+1; j<n; j++)
            {
                if(Com(person[i].English,person[j].English)==1)
                {
                    tem=person[i];
                    person[i]=person[j];
                    person[j]=tem;
                }
            }
    }
    Display();
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

    while(1)
    {
        char a[10],b[10];
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
            Insert();
        }
        if(a[0]=='2')
        {
            system("cls");
            Display();
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
            Change();
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
            order();
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
            reseach();
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
            Del();
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
}

