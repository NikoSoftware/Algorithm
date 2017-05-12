#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<windows.h>

int n=0,f;
float cout1,cout2,cout3;
char model[10][40]= {" ","大型","中型","小型"},q[10][50]= {"","按型号排序","按路程排序","按价钱排序","按时间排序"};
char m[10][100]={"","由于软件没有引入文件(FILE)函数，所以每次开启程序都需要重新输入数据。","对此带来的不便敬请谅解!"};
void Pos(short x,short y)//设置光标位置函数
{
    COORD pos;
    pos.X=x;
    pos.Y=y;
    HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput,pos);
    return;
}//Pos


struct Node
{
    int size;//(1,2,3)分别对应车型(大，中，小)、收款人（甲，乙，丙）
    float distance,price;
    long date;
} node[1000];



void write()
{
    Pos(20,2);
    printf("1.大型，2.中型，3.小型");
    Pos(20,5);
    printf("车型号：");
    Pos(20,7);
    printf("路程：");
    Pos(20,9);
    printf("价格：");
    Pos(30,5);
    scanf("%d",&node[n].size);
    while(node[n].size<=0||node[n].size>=4)
    {
        Pos(45,5);printf("输入错误，请重新输入！");
        Pos(30,5);printf("  ");
        Pos(30,5);scanf("%d",&node[n].size);
        Pos(40,5);printf("                          ");

    }
    Pos(33,5);
    printf("%s",model[node[n].size]);
    Pos(30,7);
    scanf("%f",&node[n].distance);
    Pos(35,7);
    printf("Km");
    node[n].price=(0.6-node[n].size*0.1)*node[n].distance;
    Pos(30,9);
    printf("%.2f 元",node[n].price);

    //下面取时间

    node[n].date = time((time_t*)NULL);
    struct tm *local;
    local=localtime(&node[n].date);
    Pos(16,11);
    printf("当前时间:  %d:%d:%d",local->tm_hour,local->tm_min,local->tm_sec);
    n++;
    Pos(30,13);printf("任意键继续……");
    getchar();
    getchar();

}

//打印
void Display(int x,int z)
{
    int cnt=x;
    while(cnt<z)
    {
        printf("车型：%s\t",model[node[cnt].size]);
        printf("路程：%.2f km\t",node[cnt].distance);
        printf("价格：%.2f 元\t",node[cnt].price);
        struct tm *local2;
        local2=localtime(&node[cnt].date);
        printf("时间: %d/%d/%d  %d:%d:%d\n",1900+local2->tm_year,local2->tm_mon+1, local2->tm_mday,local2->tm_hour,local2->tm_min,local2->tm_sec);
        cnt++;
    }
    printf("任意键继续……");
    getchar();
    getchar();
}


//排序
void Sort(int p)
{
    printf("\t\t\t\t%s\n\t",q[p]);
    if(n==0)
      {
           printf("内部无值\n");
        printf("任意键继续……");
    getchar();
    getchar();
      }
    else if(n==1)
           Display(0,1);

    else
    {
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                switch(p)
                {
                case 1:
                    if(node[i].size>node[j].size)
                    {
                        struct Node tem=node[i];
                        node[i]=node[j];
                        node[j]=tem;
                    }
                    break;
                case 2:
                    if(node[i].distance<node[j].distance)
                    {
                        struct Node tem=node[i];
                        node[i]=node[j];
                        node[j]=tem;
                    }
                    break;
                case 3:
                    if(node[i].price<node[j].price)
                    {
                        struct Node tem=node[i];
                        node[i]=node[j];
                        node[j]=tem;
                    }
                    break;
                case 4:
                    if(node[i].date<node[j].date)
                    {
                        struct Node tem=node[i];
                        node[i]=node[j];
                        node[j]=tem;
                    }
                    break;

                }
            }
            Display(0,n);
        }

    }
}

void Sum()
{
    int cont=0;
    cout1=cout2=cout3=0;
    while(cont<n)
    {
        switch(node[cont].size)
        {
        case(1):
            cout1+=node[cont].price;
            break;
        case(2):
            cout2+=node[cont].price;
            break;
        case(3):
            cout3+=node[cont].price;
            break;
        }
        cont++;
    }
    printf("大型车总收入: %.2f 元\n中型车总收入: %.2f 元\n小型车总收入：%.2f 元\n总收入：%.2f 元\n",cout1,cout2,cout3,cout1+cout2+cout3);
    printf("任意键继续……");
    getchar();
    getchar();

}
void moving(char *a)
{
    int n=strlen(a);
    for(int i=0; i<n; i++)
    {
        printf("%c",a[i]);
        Sleep(50);
    }
}
void image1()
{
    Pos(10,5);
    moving(m[1]);
    Pos(10,7);
    moving(m[2]);
    Pos(20,10);
    printf("任意键继续……");
    getchar();
}
void image()
{
    printf("\n\n\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\t\n");
    printf("\t■                                                      ■\t\n");
    printf("\t■                     车辆收费系统                     ■\t\n");
    printf("\t■                                                      ■\t\n");
    printf("\t■                                                      ■\t\n");
    printf("\t■                     1.进行收费                       ■\t\n");;
    printf("\t■                                                      ■\t\n");
    printf("\t■                     2.进行排序                       ■\t\n");
    printf("\t■                                                      ■\t\n");
    printf("\t■                     3.计算收入                       ■\t\n");
    printf("\t■                                                      ■\t\n");
    printf("\t■                     4.打印所有数据                   ■\t\n");
    printf("\t■                                                      ■\t\n");
    printf("\t■                     0.退出程序                       ■\t\n");
    printf("\t■                                                      ■\t\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\t\n");
    Pos(30,20);printf("请输入选择：");scanf("%d",&f);
}
int main()
{
     image1();
     system("cls");
    while(1)
    {
        int flag=0,p;
       image();
       system("cls");
       switch(f)
       {
           case 0:
           flag=1;
           break;
           case 1:
           write();
           break;
           case 2:
           printf("请输入排序的方式：1.型号，2.路程，3.价格，4.时间");
           Pos(30,1);printf("请输入：");scanf("%d",&p);
           system("cls");
           Sort(p);
           break;
           case 3:
           Sum();
           break;
           case 4:
           Display(0,n);
       }
       system("cls");
       if(flag==1)
       {
           printf("程序结束");
       break;
       }

    }




    return 0;
}
